public class WordStatistics implements Comparable<WordStatistics> {
    private String word;
    private int count;

    public WordStatistics(String word, int count) {
        this.count = count;
        this.word = word;
    }

    public int getCount() {
        return count;
    }

    public String getWord() {
        return word;
    }

    @Override
    public int compareTo(WordStatistics o) {
        return 0; // TODO: make correct compare
    }
}
