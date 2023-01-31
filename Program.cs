using System;


class Canva{

    //every "alive" cell
    private const char live = '*';
    //void space in canvas
    private const char dead = (char) 32;

    public static char[,] array = {
        {dead, dead, dead, dead, dead, dead, dead, dead, dead, dead},
        {dead, dead, dead, dead, dead, dead, dead, dead, dead, dead},
        {dead, dead, dead, live, dead, dead, live, dead, dead, dead},
        {dead, dead, live, dead, live, live, dead, live, dead, dead},
        {dead, dead, dead, live, dead, dead, live, dead, dead, dead},
        {dead, dead, dead, live, dead, dead, live, dead, dead, dead},
        {dead, dead, live, dead, live, live, dead, live, dead, dead},
        {dead, dead, dead, live, dead, dead, live, dead, dead, dead},
        {dead, dead, dead, dead, dead, dead, dead, dead, dead, dead},
        {dead, dead, dead, dead, dead, dead, dead, dead, dead, dead}
    };

    public int height = array.GetLength(0);
    public int width = array.GetLength(1);

    public void printCanva(){
        foreach (var i in Enumerable.Range(0, height)){
            foreach (var j in Enumerable.Range(0, width)){
                Console.Write(array[i,j]);
            }
            Console.WriteLine();
        }
    }

    public bool proveAlive(int row, int col){
        int near = 0;

        //get near alive cells
        for (int i = -1; i < 2; i++){
            for (int j = -1; j < 2; j++){

                if (row + i < 0 || col + j < 0) continue;
                if (row + i >= height || col + j >= width) continue;
                if (i == 0 && j == 0) continue;
                

                if(array[row + i,col + j] == live){
                    near++;
                }
            }
        }

        switch (array[row, col]){
            case live: return (near == 2 || near == 3);

            case dead: return (near == 3);
        }

        return false;
    }

    public void update(){

        char[,] aux = new char[height, width];

        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (proveAlive(i, j)){
                    aux[i,j] = live;
                }
                else {
                    aux[i,j] = dead;
                }
            }
        }

        Array.Copy(aux, array, aux.Length);

    }
}

class mainProcess{
    public static void Main(){

        Canva canva = new Canva();

        canva.printCanva();

        Thread.Sleep(1000);

        Console.Clear();

        while (true) {

            canva.update();

            canva.printCanva();

            Thread.Sleep(1000);
            
            Console.Clear();
        }

    }
}