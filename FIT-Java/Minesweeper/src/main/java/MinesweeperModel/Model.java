package MinesweeperModel;

import java.util.ArrayList;

import MinesweeperGame.App;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;



public class Model {

    private static final Logger logger = LoggerFactory.getLogger(App.class);

    private int height;
    private int width;
    private int mines;
    private boolean firstStep;
    private boolean gameOver;
    private Cell[][] cells;

    public Model() {
        logger.info("Start game");
        startGame(9,9,10);
    }


    public void startGame(int height, int width, int mines) {
        firstStep = true;
        gameOver = false;
        this.height = height;
        this.width = width;
        this.mines = mines;
        this.cells = new Cell[width][height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                cells[j][i] = new Cell(i, j, false);
            }
        }
    }

    public Cell getCell(int x, int y) {
            return this.cells[x][y];
    }

    public boolean isWin() {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                if (!cells[i][j].isMined() &&
                        (cells[i][j].getState() != CellState.OPENED
                                && cells[i][j].getState() != CellState.FLAGGED)) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isGameOver() {return gameOver;}

    public void nextCellMark(Cell cell) {
        cell.nextMark();
    }

    public void openCell(Cell cell) {

        if(firstStep) {
            cell.open();
            firstStep = false;
            generateMines();
        }

        ArrayList<Cell> neighbours = getCellNeighbours(cell);
        cell.setCounter(countMinesAroundCell(cell, neighbours));

        if(cell.open()) {
            if(cell.isMined()) {
                gameOver = true;
                System.out.println("MinesweeperGame over, cell: " + cell.getPos_x() + cell.getPos_y());
                return;
            }


            if(cell.getCounter() == 0) {

                for(Cell i : neighbours) {
                    if(i.getState() == CellState.CLOSED) {
                        openCell(i);
                    }
                }
            }
        }

    }

    private void generateMines() {
        int x, y;
        for(int i = 0; i < mines; i++) {
            while(true) {
                x = (int) (Math.random() * (this.width - 1));
                y = (int) (Math.random() * (this.height - 1));
                if(getCell(x,y).getState() != CellState.OPENED && !getCell(x,y).isMined()) {
                    getCell(x,y).setMine();

                    break;
                }
            }
        }
    }

    private int countMinesAroundCell(Cell cell, ArrayList<Cell> neighbours) {
        int sum = 0;
        int x = cell.getPos_x();
        int y = cell.getPos_y();
        for(Cell i : neighbours) {
            if(i.isMined()) {
                sum++;
            }
        }
        //System.out.println("sum= " + sum);
        return sum;
    }

    private ArrayList<Cell> getCellNeighbours(Cell cell) {

        ArrayList<Cell> neighbours = new ArrayList<Cell>();
        int x = cell.getPos_x();
        int y = cell.getPos_y();
        //System.out.println("getCellNeighbours " + x + y);
        for(int i = y - 1; i <= y + 1; i++) {
            for(int j = x - 1; j <= x + 1; j++) {
                if(!(i == x && j == y) && !((i < 0 || i >= width) || (j < 0 || j >= height))) {
                    neighbours.add(getCell(i, j));
                    //System.out.println(i + " " + j);
                }
            }
        }
        return  neighbours;
    }

    public int getWidth() {return width;}

    public int getHeight() {return height;}
}
