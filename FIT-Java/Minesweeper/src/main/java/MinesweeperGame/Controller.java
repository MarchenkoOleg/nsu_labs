package MinesweeperGame;

import MinesweeperModel.Model;
import MinesweeperView.View;
import MinesweeperModel.Cell;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class Controller extends MouseAdapter {

    private static View view;
    private static Model model;
    private Cell cell;
    private static int defaultHeight = 9;
    private static int defaultWidth = 9;
    private static int defaultMines = 10;

    public Controller(Model m) {
        model = m;
    }

    public Controller(Cell c) {
        cell = c;
    }

    public void setView(View v) {
        view = v;
    }

    public void startNewGame() {
        model.startGame(defaultHeight, defaultWidth, defaultMines);
        view = new View(model, this);
    }
    public void startNewGame(int height, int width, int mines) {
        defaultHeight = height;
        defaultWidth = width;
        defaultMines = mines;
        startNewGame();

    }

    public void mouseClicked(MouseEvent e) {
        switch (e.getButton()) {
            case MouseEvent.BUTTON1: //left
                model.openCell(cell);
                if(model.isWin()) {
                    view.showWinMessage();
                    startNewGame();
                } else if(model.isGameOver()) {
                    view.showGameOverMessage();
                    startNewGame();
                }
                break;
            case MouseEvent.BUTTON3: //right
                model.nextCellMark(cell);
                break;
            default:
                break;
        }
    }

    public static Model getModel() {
        return model;
    }

    public View getView() {
        return view;
    }
}
