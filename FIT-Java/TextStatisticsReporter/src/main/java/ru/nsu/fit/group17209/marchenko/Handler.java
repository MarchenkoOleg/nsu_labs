package ru.nsu.fit.group17209.marchenko;

import java.io.InputStream;
import java.io.Writer;

public class Handler {
    private TextStatistics stat;
    private StatisticsReport report;
    private Writer out;
    private WordReader reader;


    public Handler(InputStream input, Writer output, StatisticsReport report) {
        reader = new WordReader(input);
        out = output;
        this.report = report;
        stat = new TextStatistics();
        start();
    }

    public void start() {
        String str;
        while ((str = reader.nextWord()) != null) {
            stat.addWord(str);
        }
        report.generateReport(stat, report.prepareReport(stat), out);
    }
}
