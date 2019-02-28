package ru.nsu.fit.group17209.marchenko;

import java.io.Writer;
import java.util.TreeSet;


public abstract class StatisticsReport {
    public StatisticsReport() {}

    public TreeSet<WordStatistics> prepareReport(TextStatistics stat) {
        TreeSet<WordStatistics> set = new TreeSet<>(stat.getWords().values());
        return set;
    }

    abstract void generateReport(TextStatistics stat, TreeSet<WordStatistics> dict, Writer output);
}
