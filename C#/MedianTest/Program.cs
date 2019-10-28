using System;
using System.Collections.Generic;

namespace MedianTest
{
    class MainClass
    {
        public static void Main(string[] args)
        {
            for (int j = 0; j < 1000; j++) {
                //Console.Read();
                int k = int.Parse(Console.ReadLine());
                Console.WriteLine();
                List<int> allElement = new List<int>(20);
                List<int> T = new List<int>(10);
                List<int> S = new List<int>(10);
                Random random = new Random();

                for (int i = 0; i < 20; i++) {
                    int newInt = random.Next(200);
                    while (allElement.Contains(newInt)) newInt = random.Next(200);
                    allElement.Add(newInt);
                    if (i % 2 == 0) T.Add(newInt);
                    else S.Add(newInt);
                }

                allElement.Sort();
                T.Sort();
                S.Sort();

                foreach (int i in allElement) {
                    Console.Write(i + ",");
                }

                Console.WriteLine();

                foreach (int i in T) {
                    Console.Write(i + ",");
                }

                Console.WriteLine();

                foreach (int i in S) {
                    Console.Write(i + ",");
                }

                Console.WriteLine();
                Console.WriteLine(allElement[k - 1]);
                //Console.WriteLine(allElement.IndexOf(T[4]) + ", " + allElement.IndexOf(S[4]));

                //int tM = allElement.IndexOf(T[4]);
                //int sM = allElement.IndexOf(S[4]);
                //Console.WriteLine((tM < 9 && 9 <= sM) || (tM >= 9 && 9 > sM) ? "true" : "false");

                Console.WriteLine(KthValue(S, 0, T, 0, k));
            }
        }

        public static int KthValue(List<int> S, int a, List<int> T, int b, int k)
        {
            if (a == S.Count) return T[k - 1 + b];
            if (b == T.Count) return S[k - 1 + a];
            if (k == 1) return Math.Min(S[0 + a], T[0 + b]);

            int index = k / 2 - 1;

            if (S[index + a] < T[index + b]) {
                return KthValue(S, index + 1 + a, T, b, k - k / 2);
            } else {
                return KthValue(S, a, T, index + 1 + b, k - k / 2);
            }
        }
    }
}
