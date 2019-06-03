package MinesweeperView;

import MinesweeperModel.Cell;
import MinesweeperModel.CellListener;
import MinesweeperModel.CellState;
import MinesweeperGame.Controller;


import javax.swing.*;
import java.awt.*;

public class Button extends JButton implements CellListener {

    private Cell cell;
    private JButton button;
    private Controller controller;

    public Button(Cell c) {
        super();
        cell = c;
        button = new JButton("");
        button.setPreferredSize(new Dimension(30, 30));
        button.setMargin(new Insets(1,1,1,1));
        button.setFont(new Font("Arial", Font.PLAIN, 12));
        controller = new Controller(cell);
        button.addMouseListener(controller);
    }



    public void config(Color c, String txt) {
        config(c);
        config(txt);
    }

    public void config(Color c) {
        button.setBackground(c);
    }

    public void config(String txt) {
        button.setText(txt);
    }

    public JButton getButton() {
        return this.button;
    }

    @Override
    public void cellUpdated(Cell cell) {
        if(controller.getModel().isGameOver() && cell.isMined()) {
            config(Color.BLACK, "");
            //controller.getView().syncWithModel();
            return;
        }
        if(cell.getState() == CellState.CLOSED) {
            config("");
        } else if(cell.getState() == CellState.OPENED) {
            config(Color.LIGHT_GRAY, "");
            if(cell.isMined()) {
                config(Color.RED);
            } else if(cell.getCounter() > 0) {
                config(Integer.toString(cell.getCounter()));
            }
        } else if(cell.getState() == CellState.FLAGGED) {
            config("P");
        } else if(cell.getState() == CellState.QUESTIONED) {
            config("?");
        }
    }
}
