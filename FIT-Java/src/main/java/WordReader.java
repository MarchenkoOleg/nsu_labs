import java.io.InputStream;
import java.io.InputStreamReader;

public class WordReader {
    private InputStreamReader stream;

    public WordReader(InputStream stream) {
        this.stream = new InputStreamReader(stream);
    }

}
