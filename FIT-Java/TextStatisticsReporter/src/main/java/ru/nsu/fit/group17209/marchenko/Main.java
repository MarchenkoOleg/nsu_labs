package ru.nsu.fit.group17209.marchenko;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;

public class Main {
    public static void main(String[] args) throws Exception{
        if (args.length < 1) {
            System.err.println("Not enough arguments.");
            return;
        }
        String reportFileName;
        CSVReport report = new CSVReport();
        File inFile = new File(args[0]);
        InputStream in = new FileInputStream(inFile);
        if(args.length >= 2)
            reportFileName = args[1];
        else
            reportFileName = "src/report.csv";
        FileWriter out = new FileWriter(reportFileName);
        new Handler(in, out, report);

    }
}
