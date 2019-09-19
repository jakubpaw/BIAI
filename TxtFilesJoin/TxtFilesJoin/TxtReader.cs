using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TxtFilesJoin
{
    static class TxtReader
    {
        public static string Read(string trainOrValid, string diceType, int number)
        {
            string path = trainOrValid + "/" + diceType + "/dice (" + number.ToString() + ").txt";

            string ret=" ";

            try
            {
                if (File.Exists(path))
                {
                    using (StreamReader sr = new StreamReader(path))
                    {
                        ret = sr.ReadLine();

                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("The process failed: {0}", e.ToString());
            }
            return ret;
        }
        public static List<string> MakeAllInputsOfTargetDiceType(string trainOrValid, string diceType, int count)
        {
            List<string> ret = new List<string>();
            for (int i = 1; i <= count; i++)
            {
                string str = TxtReader.Read(trainOrValid, diceType, i);
                ret.Add(str);
            }
            return ret;
        }
    }


}
