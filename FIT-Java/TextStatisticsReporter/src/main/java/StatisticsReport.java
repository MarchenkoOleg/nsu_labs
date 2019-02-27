import java.io.Writer;
import java.util.HashMap;
import java.util.TreeSet;


public abstract class StatisticsReport {
    public StatisticsReport() {}

    public TreeSet<WordStatistics> prepareReport(TextStatistics stat) {
        HashMap<String,WordStatistics> map = stat.getWords();
        TreeSet<WordStatistics> set = new TreeSet<>(map.values());
        return set;
    }

    abstract void generateReport(TextStatistics stat, TreeSet<WordStatistics> dict, Writer output);
}
