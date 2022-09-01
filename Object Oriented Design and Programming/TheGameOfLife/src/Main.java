import java.io.IOException;
import java.util.ArrayList;
public class Main {
    int[][] MainGen = new int[20][20];
    int[][] MainNextGen = new int[20][20];
    public static void main(String[] args)throws IOException, InterruptedException {
        Main game = new Main();
        for (int i = 0; i < 10; i++) {
            game.version1();
        }
        System.out.println("Latest Generation");
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                if (game.MainGen[i][j] == 0)
                    System.out.print("O");
                else
                    System.out.print("X");
            }
            System.out.println();
        }
        System.out.println();
    }
    public void version1(){
        Thread thread[] = new Thread[400];
        int index = 0;
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                thread[index] = new Thread(new GameOfLife(i, j, MainGen, MainNextGen));
                thread[index].start();
                index++;
            }
        }
        try
        {
            for (int i = 0; i < 400; i++)
            {
                thread[i].join();
            }

        }
        catch (Exception e)
        {
            System.out.println(e);
        }
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
                MainGen[i][j] = MainNextGen[i][j];
            }
        }
    }
}