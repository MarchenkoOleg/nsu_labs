package MinesweeperView;

import MinesweeperGame.Controller;
import MinesweeperModel.Model;
import MinesweeperModel.Cell;

import javax.swing.*;
import java.awt.*;


public class View extends JPanel {

    static private JFrame frame = new JFrame("Minesweeper");
    private JPanel view;
    private JPanel menu;
    private Model model;
    private Button[][] field;

    public View(Model model, Controller controller) {

        frame.setContentPane(this);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setResizable(true);
        frame.setAlwaysOnTop(true);
        this.model = model;
        controller.setView(this);
        view = new JPanel();
        view.setLayout(new GridLayout(model.getHeight(), model.getWidth()));
        field = new Button[model.getHeight()][model.getWidth()];
        buildButtons();
        //frame.add(view, BorderLayout.SOUTH);
        frame.add(view);
        menu = new JPanel();
        JButton newMenu = new JButton("Новая игра");
        JButton highScoresMenu = new JButton ("Рекорды");
        JButton aboutMenu = new JButton ("About");
        JButton exitMenu = new JButton ("Выход");


        menu.add(newMenu);
        menu.add(highScoresMenu);
        menu.add(aboutMenu);
        menu.add(exitMenu);
        //frame.setJMenuBar(menu);
        frame.pack();

    }

    public void syncWithModel() {
        /*
        for (int i = 0; i < model.getHeight(); i++) {
            for (int j = 0; j < model.getWidth(); j++) {
                MinesweeperModel.MinesweeperModel.Cell cell = model.getCell(i, j);
                MinesweeperView.MinesweeperView.Button btn = field[i][j];

                if(model.isGameOver() && cell.isMined()) {
                    btn.config(Color.BLACK, "");
                }
                if(cell.getState() == MinesweeperModel.MinesweeperModel.CellState.CLOSED) {
                    btn.config("");
                } else if(cell.getState() == MinesweeperModel.MinesweeperModel.CellState.OPENED) {
                    btn.config(Color.LIGHT_GRAY, "");
                    if(cell.getCounter() > 0) {
                        btn.config(Integer.toString(cell.getCounter()));
                    } else if(cell.isMined()) {
                        btn.config(Color.RED);
                    }
                } else if(cell.getState() == MinesweeperModel.MinesweeperModel.CellState.FLAGGED) {
                    btn.config("P");
                } else if(cell.getState() == MinesweeperModel.MinesweeperModel.CellState.QUESTIONED) {
                    btn.config("?");
                }
            }
        }*/
    }

    private void buildButtons() {

        for (int i = 0; i < model.getHeight(); i++) {
            for (int j = 0; j < model.getWidth(); j++) {
                Cell cell = model.getCell(i, j);
                //System.out.println(cell.getState());
                Button button = new Button(cell);
                field[i][j] = button;
                this.view.add(button.getButton());
                cell.clearListeners();
                cell.addListener(button);
                System.out.println("Listener added");
            }
        }


    }

    public void showWinMessage() {
        JOptionPane.showMessageDialog(frame, "Поздравляем, Вы победили!");
    }

    public void showGameOverMessage() {
        JOptionPane.showMessageDialog(frame, "Игра окончена, Вы проиграли!");
    }

    public void showGameSettings() {

    }

}
