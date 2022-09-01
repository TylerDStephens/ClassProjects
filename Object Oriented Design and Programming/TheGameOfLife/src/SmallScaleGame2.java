import java.util.Arrays;

public class SmallScaleGame2 {
    public static void main(String[] args)
    {
        int M = 20, N = 20;

        // Intiliazing the grid.
        int[][] grid = {
                { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0 },
                { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0 },
                { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 },
                { 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0 },
                { 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 },
                { 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
                { 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
                { 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0 },

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
                        future[i][j] = 0;
                    else
                        future[i][j] = 1;
                }
            }
        }
    }
}
