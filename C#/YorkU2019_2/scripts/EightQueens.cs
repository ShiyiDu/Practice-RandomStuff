using System;
using System.Collections.Generic;

class MainClass
{
    public static List<bool> chestBoard = new List<bool>();

    public static void Main(string[] args)
    {
        for (int i = 0; i < 8; i++) {
            string read = Console.ReadLine();

            for (int j = 0; j < 8; j++) {
                if (read[j].Equals('*'))
                    chestBoard.Add(true);
                else
                    chestBoard.Add(false);
            }
        }

        if (check()) {
            Console.WriteLine("valid");
        } else {
            Console.WriteLine("invalid");
        }

    }

    public static bool check()
    {
        int counter = 0;
        for (int i = 0; i < chestBoard.Count; i++) {
            if (chestBoard[i]) {
                counter++;
                if (!checkPiece(i)) {
                    return false;
                }
            }
        }
        if (counter < 8) return false;

        return true;
    }

    public static bool checkPiece(int pos)
    {
        int checking = pos;
        int row = pos / 8;
        int col = pos % 8;
        //horizontal

        for (int i = row * 8; i < row * 8 + 8; i++) {
            if (i == pos) continue;
            if (chestBoard[i]) return false;
        }

        //vertical
        for (int i = col; i < 64; i += 8) {
            if (i == pos) continue;
            if (chestBoard[i]) return false;
        }

        //up left
        checking = pos;
        checking -= 9;
        while (checking > -1 && (checking + 1) % 8 != 0) {
            if (chestBoard[checking]) return false;
            //if (checking % 8 == 0) break;
            else checking -= 9;
        }

        //up right
        checking = pos;
        checking -= 7;
        while (checking > -1 && (checking) % 8 != 0) {
            if (chestBoard[checking]) return false;
            //if ((checking + 1) % 8 == 0) break;
            else checking -= 7;
        }

        //Console.WriteLine("diaganal");
        //down left
        checking = pos;
        checking += 7;
        while (checking < 64 && ((checking + 1) % 8 != 0)) {
            if (chestBoard[checking]) return false;
            //if (checking % 8 == 0) break;
            else checking += 7;
        }

        //Console.WriteLine("diaganal");
        //down right
        checking = pos;
        checking += 9;
        while (checking < 64 && ((checking) % 8 != 0)) {
            if (chestBoard[checking]) return false;
            //if ((checking + 1) % 8 == 0) break;
            else checking += 9;
        }

        //Console.WriteLine("diaganal");
        return true;
    }
}
