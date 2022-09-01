import java.util.Arrays;

public class SmallScaleGame {
    public static void main(String[] args)
    {
        int M = 4, N = 4;

        // Intiliazing the grid.
        int[][] grid = {
                { 0, 1, 1, 1 },
                { 0, 0, 1, 1,},
                { 0, 1, 0, 1,},
                { 1, 0, 0, 0,},
        };
        int[][] newgrid = grid;
        System.out.println("Original Generation");
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                    System.out.print("O");
                else
                    System.out.print("X");
            }
            System.out.println();
        }
        System.out.println();
        nextGeneration(newgrid, M, N);
    }

    // Function to print next generation
    static void nextGeneration(int newgrid[][], int M, int N)
    {
        int[][] future = new int[M][N];
        for( int t = 0; t < 3; t++) {
            System.out.println("Times " + t);
            for (int l = 1; l < M - 1; l++) {
                for (int m = 1; m < N - 1; m++) {
                    int aliveNeighbours = 0;
                    for (int i = -1; i <= 1; i++)
                        for (int j = -1; j <= 1; j++)
                            aliveNeighbours += newgrid[l + i][m + j];

                    // The cell needs to be subtracted from
                    // its neighbours as it was counted before
                    aliveNeighbours -= newgrid[l][m];

                    // Implementing the Rules of Life

                    // Cell is lonely and dies
                    if ((newgrid[l][m] == 1) && (aliveNeighbours < 2))
                        future[l][m] = 0;

                        // Cell dies due to over population
                    else if ((newgrid[l][m] == 1) && (aliveNeighbours > 3))
                        future[l][m] = 0;

                        // A new cell is born
                    else if ((newgrid[l][m] == 0) && (aliveNeighbours == 3))
                        future[l][m] = 1;

                        // Remains the same
                    else
                        future[l][m] = newgrid[l][m];
                }
            }
            System.out.println("Current Generation");
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (future[i][j] == 0)
                        System.out.print("O");
                    else
                        System.out.print("X");
                }
                System.out.println();
            }
            for (int i = 0; i < M; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (future[i][j] == 0)
                        newgrid[i][j] = 0;
                    else
                        newgrid[i][j] = 1;
                }
            }
        }
    }
}

/* public static void version1(long numberTrials, int count) throws InterruptedException {
        System.out.println("\nStarting GameOfLife ");
        int M =20, N=20;
        int[][] Currentgrid = new int[M][N];
        ArrayList<GameOfLife> game = new ArrayList<>();
        for (int i=0; i<count; i++) game.add(new GameOfLife(numberTrials/count));
        long startTime = System.currentTimeMillis();
        for (int i=0; i<count; i++) game.get(i).start();
        for (int i=0; i<count; i++) game.get(i).t.join();
        long estimatedTime = System.currentTimeMillis() - startTime;
        for (int i=0; i<count; i++) {
            int[][] future = new int[M][N];
            for (int l = 1; l < M - 1; l++) {
                for (int m = 1; m < N - 1; m++) {
                    int aliveNeighbours = 0;
                    for (int y = -1; i <= 1; i++)
                        for (int j = -1; j <= 1; j++)
                            aliveNeighbours += Currentgrid[l + y][m + j];
                    aliveNeighbours -= Currentgrid[l][m];
                    if ((Currentgrid[l][m] == 1) && (aliveNeighbours < 2))
                        future[l][m] = 0;
                    else if ((Currentgrid[l][m] == 1) && (aliveNeighbours > 3))
                        future[l][m] = 0;
                    else if ((Currentgrid[l][m] == 0) && (aliveNeighbours == 3))
                        future[l][m] = 1;
                    else
                        future[l][m] = Currentgrid[l][m];
                }
            }
            for (int q = 0; q < M; q++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (future[q][j] == 0)
                        Currentgrid[q][j] = 0;
                    else
                        Currentgrid[q][j] = 1;
                }
            }
        }
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Currentgrid[i][j] == 0)
                    System.out.print("O");
                else
                    System.out.print("X");
            }
            System.out.println();
        }
        System.out.printf("Took %d ms\n",  estimatedTime);
    }*/
/*
void nextGeneration(int CurrentGen[][], int M, int N) {

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (future[i][j] == 0)
                    CurrentGen[i][j] = 0;
                else
                    CurrentGen[i][j] = 1;
            }
        }

        System.out.println("Original Generation");
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Originalgrid[i][j] == 0)
                    System.out.print("O");
                else
                    System.out.print("X");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println("Current Generation");
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (Currentgrid[i][j] == 0)
                    System.out.print("O");
                else
                    System.out.print("X");
            }
            System.out.println();
        }
        System.out.println();
    }*/