public class GameOfLife implements Runnable {
    int M = 20, N = 20, Z, X;
    long numberTrials;
    int[][] OriginalGen = {
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0},
            {0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0},
            {1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0},
            {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0},

    };
    int[][] CurrentGen = new int[N][M];
    int[][] NextGen = new int[N][M];
    public void setGrid() {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (OriginalGen[i][j] == 0)
                    CurrentGen[i][j] = 0;
                else
                    CurrentGen[i][j] = 1;
            }
        }
    }
    public Thread t;
    public void start() {
        t = new Thread(this);
        t.start();
    }
    public GameOfLife( int X, int Z, int[][] CurrentGen, int[][] NextGen){
        this.X = X;
        this.Z = Z;
        this.CurrentGen = CurrentGen;
        this.NextGen = NextGen;
        //this.numberTrials = numberTrials;
    }
    @Override
    public void run() {
        setGrid();
        //nextGeneration(CurrentGen, N, M);
        boolean life = IsAlive();
        if(life)
            NextGen[X][Z] = 1;
        else
            NextGen[X][Z] = 0;
    }
    public boolean IsAlive(){
        //int[][] future = new int[M][N];
        for (int l = 1; l < M - 1; l++) {
            for (int m = 1; m < N - 1; m++) {
                int aliveNeighbours = 0;
                for (int i = -1; i <= 1; i++)
                    for (int j = -1; j <= 1; j++)
                        aliveNeighbours += CurrentGen[l + i][m + j];
                aliveNeighbours -= CurrentGen[l][m];
                if ((CurrentGen[l][m] == 0) && (aliveNeighbours == 3))
                    return true; //future[l][m] = 0;
                //else if ((CurrentGen[l][m] == 1) && (aliveNeighbours > 3))
                    //return false; //future[l][m] = 0;
                else if ((CurrentGen[l][m] == 1) && (aliveNeighbours == 3 || aliveNeighbours == 2))
                    return true; //future[l][m] = 1;
                else
                    return false; //future[l][m] = CurrentGen[l][m];
            }
        }
        return false;
    }
}
