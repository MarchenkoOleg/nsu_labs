package MinesweeperView;

import MinesweeperGame.Controller;
import MinesweeperModel.CellState;
import MinesweeperModel.Model;
import MinesweeperModel.Cell;
import MinesweeperModel.TimerListener;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class View extends JPanel implements TimerListener {

    static private JFrame frame = new JFrame("Minesweeper");
    private JPanel view;
    private JTextField time;
    private Model model;
    private Button[][] field;

    public View(Model model, Controller controller) {
        model.clearListeners();
        model.addListener(this);
        frame.setContentPane(this);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
        frame.setResizable(true);
        frame.setAlwaysOnTop(true);
        this.model = model;
        controller.setView(this);
        view = new JPanel();
        time = new JTextField("0");
        time.setEnabled(false);

        view.setLayout(new GridLayout(model.getHeight(), model.getWidth()));
        field = new Button[model.getHeight()][model.getWidth()];
        buildButtons();
        frame.add(view);

        JMenuBar bar = new JMenuBar();

        JMenu game = new JMenu("Game");

        JMenu new_game_item = new JMenu("New game");
        final JMenuItem beginner = new JMenuItem("Beginner");
        final JMenuItem intermediate = new JMenuItem("Intermediate");
        final JMenuItem expart = new JMenuItem("Expert");
        final JMenuItem exit = new JMenuItem("Exit");
        final JMenu help = new JMenu("Help");
        final JMenuItem helpitem = new JMenuItem("Help");

        ButtonGroup status = new ButtonGroup();


        beginner.addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        controller.startNewGame(9, 9, 10);
                    }
                });
        intermediate.addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        controller.startNewGame(14, 14, 20);
                    }
                });
        expart.addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent e) {
                        controller.startNewGame(20, 20, 40);
                    }
                });


        exit.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        helpitem.addActionListener(new ActionListener() {

            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(null, "Help");

            }
        });

        frame.setJMenuBar(bar);

        status.add(beginner);
        status.add(intermediate);
        status.add(expart);

        game.add(new_game_item);
        game.addSeparator();
        new_game_item.add(beginner);
        new_game_item.add(intermediate);
        new_game_item.add(expart);
        game.addSeparator();
        game.add(exit);
        help.add(helpitem);

        bar.add(game);
        bar.add(help);
        frame.add(time);
        frame.pack();

    }

    private void buildButtons() {

        for (int i = 0; i < model.getHeight(); i++) {
            for (int j = 0; j < model.getWidth(); j++) {
                Cell cell = model.getCell(i, j);
                Button button = new Button(cell);
                field[i][j] = button;
                this.view.add(button.getButton());
                cell.clearListeners();
                cell.addListener(button);
            }
        }


    }

    public void syncWithModel() {

        for (int i = 0; i < model.getHeight(); i++) {
            for (int j = 0; j < model.getWidth(); j++) {
                Cell cell = model.getCell(i, j);
                Button btn = field[i][j];
                if(model.isGameOver() && cell.isMined()) {
                    btn.config(Color.BLACK, "");
                }
                if(cell.getState() == CellState.CLOSED) {
                    btn.config("");
                } else if(cell.getState() == CellState.OPENED) {
                    btn.config(Color.LIGHT_GRAY, "");
                    if(cell.getCounter() > 0) {
                        btn.config(Integer.toString(cell.getCounter()));
                    } else if(cell.isMined()) {
                        btn.config(Color.RED);
                    }
                } else if(cell.getState() == CellState.FLAGGED) {
                    btn.config("P");
                } else if(cell.getState() == CellState.QUESTIONED) {
                    btn.config("?");
                }
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

    @Override
    public void TimerUpdated() {
        SwingUtilities.invokeLater(() -> time.setText(Integer.toString(model.getTime())));
    }
}
