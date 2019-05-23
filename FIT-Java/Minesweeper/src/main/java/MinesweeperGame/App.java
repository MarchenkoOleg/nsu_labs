package MinesweeperGame;

import java.io.IOException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import MinesweeperModel.Model;
import MinesweeperView.View;

public class App {

    private static final Logger logger = LoggerFactory.getLogger(App.class);

    public static void main(String[] argv) throws IOException {
        logger.info("public static void main(String[] argv)");
        Model model = new Model();
        new View(model, new Controller(model));

    }
}
