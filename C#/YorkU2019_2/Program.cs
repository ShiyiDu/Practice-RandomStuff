using System;
using System.Collections.Generic;
using System.Linq;

class MainClass
{
    public static List<bool> chestBoard = new List<bool>();

    public static void Main(string[] args)
    {
        int n = 0;
        int r = 0;

        string read = Console.ReadLine();
        n = int.Parse(read.Split(' ')[0]);
        r = int.Parse(read.Split(' ')[1]);

        read = Console.ReadLine();
        List<string> allReads = new List<String>();
        List<int> allTrees = new List<int>();

        allReads = read.Split(' ').ToList();

        int highest = 0;
        foreach (string str in allReads) {
            allTrees.Add(int.Parse(str));
            if (int.Parse(str) > highest) highest = int.Parse(str);
        }

        //must perform a binary search here
        long sum = 0;
        int start = 0, end = highest, result;

        //todo: why +1 or -1 for binary search
        while (true) {
            result = (end + start + 1) / 2;

            sum = 0;
            foreach (int i in allTrees) {
                sum += Math.Max(i - result, 0);
            }

            if (sum >= r) start = result;
            else if (sum < r) end = result - 1;

            if (end <= start) break;
        }

        Console.WriteLine(start);

    }

}
