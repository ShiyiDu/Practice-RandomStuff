using System;
using System.Collections.Generic;
using System.Linq;
class Untitled
{
	
	static Dictionary<string, int> test = new Dictionary<string, int> ();
	static void Main(string[] args)
	{
		for(int i = 0; i < 10; i++){
			test.Add(i.ToString(), i);
		}
		
		List<string> testList = test.Keys.ToList();
		
		testList[1] = "2000";
		
		foreach(string str in test.Keys){
			Console.Write(str);
		}
		 
	}
}