package ru.nsu.fit.group17209.marchenko;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

public class WordReader {
    private InputStreamReader stream;
    private StringBuilder builder;

    public WordReader(InputStream stream) {
        this.stream = new InputStreamReader(stream);
        builder = new StringBuilder(1000);
    }

    public String nextWord() {
        int c;
        boolean midWord = false;
        builder.setLength(0);
        try {
            while ((c = stream.read()) != -1) {
                if (!Character.isLetterOrDigit((char) c) ) {
                    if ( midWord) {
                        return builder.toString();
                    }
                } else {
                    midWord = true;
                    builder.append((char) c);
                }
            }
            if (!builder.toString().equals("")) {
                return builder.toString();
            }
        } catch (IOException e) {
            System.err.println("Error while reading file: " + e.getLocalizedMessage());
        }
        return null;
    }
}
