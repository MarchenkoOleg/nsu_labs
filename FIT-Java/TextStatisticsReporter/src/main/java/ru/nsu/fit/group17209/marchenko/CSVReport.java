package ru.nsu.fit.group17209.marchenko;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Locale;
import java.util.TreeSet;

public class CSVReport extends StatisticsReport {
    @Override
    void generateReport(TextStatistics stat, TreeSet<WordStatistics> words, Writer output) {
        try (BufferedWriter bufWriter = new BufferedWriter(output)) {
            for (WordStatistics i : words) {
                String line = String.format(Locale.US,"%s,%d,%.2f%%\n",
                                                i.getWord(),
                                                i.getCount(),
                                                ((double) i.getCount() / stat.getCount()) * 100);
                bufWriter.write(line);
            }
        } catch (IOException e) {
            System.err.println("Error while writing to file: " + e.getLocalizedMessage());
        }
    }
}
