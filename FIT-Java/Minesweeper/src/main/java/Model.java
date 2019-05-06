import java.util.ArrayList;

public class Model {

    private int height;
    private int width;
    private int mines;
    private boolean firstStep;
    private boolean gameOver;
    private Cell[][] cells;

    public Model() {
        startGame(5,5,3);
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
                        (cells[i][j].getState() != "opened" && cells[i][j].getState() != "flagged")) {
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isGameOver() {return gameOver;}

    public void nextCellMark(int x, int y) {
        Cell cell = getCell(x, y);
        cell.nextMark();
    }

    public void openCell(Cell cell) {
        cell.open();

        if(cell.isMined()) {
            gameOver = true;
            return;
        }

        if(firstStep) {
            firstStep = false;
            generateMines();
        }

        cell.setCounter(countMinesAroundCell(cell));
        if(cell.getCounter() == 0) {
            ArrayList<Cell> neighbours = getCellNeighbours(cell);
            for(Cell i : neighbours) {
                if(i.getState() == "closed") {
                    openCell(i);
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
                if(getCell(x,y).getState() != "opened" && !getCell(x,y).isMined()) {
                    getCell(x,y).setMine();
                    break;
                }
            }
        }
    }

    private int countMinesAroundCell(Cell cell) {
        int sum = 0;
        ArrayList<Cell> neighbours = getCellNeighbours(cell);
        for(Cell i : neighbours) {
            if(i.isMined()) {
                sum++;
            }
        }
        return sum;
    }

    private ArrayList<Cell> getCellNeighbours(Cell cell) {
        ArrayList<Cell> neighbours = new ArrayList<Cell>();
        int x = cell.getPos_x();
        int y = cell.getPos_y();
        System.out.println("getCellNeighbours " + x + y);
        for(int i = y - 1; i <= y + 1; i++) {
            for(int j = x - 1; j <= x + 1; j++) {
                if(!(i == x && j == y) && !((i < 0 || i >= width) || (j < 0 || j >= height))) {
                    neighbours.add(getCell(i, j));
                }
                System.out.println(i + " " + j);
            }
        }
        return  neighbours;
    }

    public int getWidth() {return width;}

    public int getHeight() {return height;}
}
