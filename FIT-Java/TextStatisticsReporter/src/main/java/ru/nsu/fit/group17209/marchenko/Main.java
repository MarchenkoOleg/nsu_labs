package ru.nsu.fit.group17209.marchenko;

import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        if (args.length < 1) {
            System.err.println("Not enough arguments.");
            return;
        }
        String reportFileName;
        CSVReport report = new CSVReport();
        try {
            File inFile = new File(args[0]);
            InputStream in = new FileInputStream(inFile);
            if(args.length >= 2) {
                reportFileName = args[1];
            } else {
                reportFileName = "src/report.csv";
            }
            FileWriter out = new FileWriter(reportFileName);
            new Handler(in, out, report);
            try {
                in.close();
                out.close();
            } catch (IOException e) {
                System.err.println("Error while closing file: " + e.getLocalizedMessage());
            }
        } catch (IOException e) {
            System.err.println("Error while opening to file: " + e.getLocalizedMessage());
        }
    }
}
