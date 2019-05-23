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
        System.out.println("NewGame");
        model.startGame(9,9,10);
        view = new View(model, this);
    }

    public void mouseClicked(MouseEvent e) {
        System.out.println(cell.getPos_x() + " " + cell.getPos_y());
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
}
