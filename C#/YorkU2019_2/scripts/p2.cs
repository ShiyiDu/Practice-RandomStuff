using System;
using System.Collections.Generic;

namespace YorkU2019_2
{
    class MainClass
    {
        public static string zero =
            "+---+" +
            "|   |" +
            "|   |" +
            "+   +" +
            "|   |" +
            "|   |" +
            "+---+";
        public static string one =
            "    +" +
            "    |" +
            "    |" +
            "    +" +
            "    |" +
            "    |" +
            "    +";
        public static string two =
            "+---+" +
            "    |" +
            "    |" +
            "+---+" +
            "|    " +
            "|    " +
            "+---+";
        public static string three =
            "+---+" +
            "    |" +
            "    |" +
            "+---+" +
            "    |" +
            "    |" +
            "+---+";
        public static string four =
            "+   +" +
            "|   |" +
            "|   |" +
            "+---+" +
            "    |" +
            "    |" +
            "    +";
        public static string five =
            "+---+" +
            "|    " +
            "|    " +
            "+---+" +
            "    |" +
            "    |" +
            "+---+";
        public static string six =
            "+---+" +
            "|    " +
            "|    " +
            "+---+" +
            "|   |" +
            "|   |" +
            "+---+";
        public static string seven =
            "+---+" +
            "    |" +
            "    |" +
            "    +" +
            "    |" +
            "    |" +
            "    +";
        public static string eight =
            "+---+" +
            "|   |" +
            "|   |" +
            "+---+" +
            "|   |" +
            "|   |" +
            "+---+";
        public static string nine =
            "+---+" +
            "|   |" +
            "|   |" +
            "+---+" +
            "    |" +
            "    |" +
            "+---+";

        public static void Main(string[] args)
        {
            while (true) {
                string read = Console.ReadLine();
                if (read.Equals("end")) {
                    Console.WriteLine("end");
                    break;
                } else {
                    int a = int.Parse(read[0] + "");
                    int b = int.Parse(read[1] + "");
                    int c = int.Parse(read[3] + "");
                    int d = int.Parse(read[4] + "");
                    PrintTime(a, b, c, d);
                    Console.WriteLine("\n");
                }
            }
        }

        public static void PrintTime(int a, int b, int c, int d)
        {
            int l = 0;
            string first =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "     " + GetSeg(c, l) + "  " + GetSeg(d, l);
            l = 1;
            string second =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "     " + GetSeg(c, l) + "  " + GetSeg(d, l);
            l = 2;
            string third =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "  o  " + GetSeg(c, l) + "  " + GetSeg(d, l); ;
            l = 3;
            string fourth =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "     " + GetSeg(c, l) + "  " + GetSeg(d, l); ;
            l = 4;
            string fifth =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "  o  " + GetSeg(c, l) + "  " + GetSeg(d, l); ;
            l = 5;
            string sixth =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "     " + GetSeg(c, l) + "  " + GetSeg(d, l); ;
            l = 6;
            string seventh =
                GetSeg(a, l) + "  " + GetSeg(b, l) + "     " + GetSeg(c, l) + "  " + GetSeg(d, l); ;
            l = 7;

            Console.WriteLine(first);
            Console.WriteLine(second);
            Console.WriteLine(third);
            Console.WriteLine(fourth);
            Console.WriteLine(fifth);
            Console.WriteLine(sixth);
            Console.WriteLine(seventh);
        }

        public static string GetSeg(int num, int line)
        {
            string result = "";
            string target = "";
            switch (num) {
                case 0:
                    target = zero;
                    break;
                case 1:
                    target = one;
                    break;
                case 2:
                    target = two;
                    break;
                case 3:
                    target = three;
                    break;
                case 4:
                    target = four;
                    break;
                case 5:
                    target = five;
                    break;
                case 6:
                    target = six;
                    break;
                case 7:
                    target = seven;
                    break;
                case 8:
                    target = eight;
                    break;
                case 9:
                    target = nine;
                    break;
            }
            result = target.Remove(0, line * 5);
            if (result.Length > 5) result = result.Remove(5);
            return result;
        }
    }
}

