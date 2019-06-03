package MinesweeperGame;

import java.io.IOException;

import MinesweeperModel.Model;
import MinesweeperView.View;

public class App {

    public static void main(String[] argv) {

        Model model = new Model();
        new View(model, new Controller(model));

    }
}
