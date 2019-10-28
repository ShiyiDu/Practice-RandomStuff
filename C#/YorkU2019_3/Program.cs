using System;
using System.Collections.Generic;

namespace YorkU2019_3
{
    class MainClass
    {
        public static void Main(string[] args)
        {
        }
    }

    public struct Vector2
    {
        private double x, y;
        public static readonly Vector2 Empty = new Vector2();

        public Vector2(double x, double y)
        {
            this.x = x;
            this.y = y;
        }

        #region Properties
        public double X
        {
            get { return x; }
            set { x = value; }
        }

        public double Y
        {
            get { return y; }
            set { y = value; }
        }
        #endregion

        public static double Distance(Vector2 a, Vector2 b)
        {
            return Math.Sqrt(Math.Pow((a.X - b.X), 2) + Math.Pow((a.Y - b.Y), 2));
        }

    }
}

//class MainClass
//{
//    public static void Main(string[] args)
//    {
//        while (true) {
//            string read = Console.ReadLine();
//            float d = float.Parse(read.Split(' ')[0]); //with in d fight and sour
//            int N = int.Parse(read.Split(' ')[1]); //number of hives
//            if (d == 0.0 && N == 0) return;

//            if (N == 0) {
//                Console.WriteLine("0 sour, 0 sweet");
//                return;
//            }

//            List<Vector2> allHives = new List<Vector2>();
//            for (int i = 0; i < N; i++) {
//                string[] positionStr = Console.ReadLine().Split(' ');
//                Vector2 pos = new Vector2(double.Parse(positionStr[0]), double.Parse(positionStr[1]));
//                allHives.Add(pos);
//            }
//            int sour = 0;
//            int sweet = 0;
//            for (int i = 0; i < allHives.Count; i++) {
//                bool bsweet = true;
//                for (int j = 0; j < allHives.Count; j++) {
//                    if (i == j) continue;
//                    if (Vector2.Distance(allHives[i], allHives[j]) <= d) {
//                        //Console.WriteLine(Vector2.Distance(allHives[i], allHives[j]));
//                        sour++;
//                        bsweet = false;
//                        break;
//                    }
//                }
//                if (bsweet) sweet++;
//            }

//            Console.WriteLine(sour + " sour, " + sweet + " sweet");
//        }
//    }
//}
//namespace YorkU2019_3
//{
//    class MainClass
//    {
//        public static void Main(string[] args)
//        {
//            string read = Console.ReadLine();

//            string[] pars = read.Split(' ');

//            int N = int.Parse(pars[0]); //people
//            int B = int.Parse(pars[1]); //budget
//            int H = int.Parse(pars[2]); //hotels
//            int W = int.Parse(pars[3]); //weeks to consider

//            List<int> budgetChoice = new List<int>();

//            for (int i = 0; i < H; i++) {
//                int budget = int.Parse(Console.ReadLine());
//                string beds = Console.ReadLine();
//                string[] bedChoices = beds.Split(' ');

//                for (int j = 0; j < W; j++) {
//                    if (int.Parse(bedChoices[j]) >= N) {
//                        budgetChoice.Add(N * budget);
//                        break;
//                    }
//                }
//            }

//            if (budgetChoice.Count == 0) {
//                Console.WriteLine("stay home");
//                return;
//            }

//            int minCost = budgetChoice[0];

//            for (int i = 0; i < budgetChoice.Count; i++) {
//                if (budgetChoice[i] < minCost) minCost = budgetChoice[i];
//            }

//            Console.WriteLine(minCost <= B ? minCost.ToString() : "stay home");

//        }
//    }
//}

