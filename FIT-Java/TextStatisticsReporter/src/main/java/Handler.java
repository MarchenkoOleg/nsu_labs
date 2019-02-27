import java.io.File;
import java.io.InputStream;
import java.io.Writer;
import java.util.Scanner;

public class Handler {
    private InputStream in;
    private TextStatistics stat;
    private StatisticsReport report;
    private Writer out;


    public Handler(InputStream input, Writer output, StatisticsReport report) {
        in = input;
        out = output;
        this.report = report;
        stat = new TextStatistics();
    }

    public void start() {
        Scanner sc = new Scanner(in);
        while (sc.hasNext()) {
            String str = sc.next();
            stat.addWord(str);
        }
        report.generateReport(stat, report.prepareReport(stat), out);
    }


}
