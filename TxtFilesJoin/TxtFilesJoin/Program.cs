using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TxtFilesJoin
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> vec1 = TxtReader.MakeAllInputsOfTargetDiceType("train", "d4", 1947);    //max 1947
            List<string> vec2 = TxtReader.MakeAllInputsOfTargetDiceType("train", "d6", 4046);    //max 4046
            List<string> vec3 = TxtReader.MakeAllInputsOfTargetDiceType("train", "d8", 1532);  //max 1532
            List<string> vec4 = TxtReader.MakeAllInputsOfTargetDiceType("train", "d10", 1722); //max 1722
            List<string> vec5 = TxtReader.MakeAllInputsOfTargetDiceType("train", "d12", 1691); //max 1691
            List<string> vec6 = TxtReader.MakeAllInputsOfTargetDiceType("train", "d20", 3346);	//max 3346
            List<string> vec7 = TxtReader.MakeAllInputsOfTargetDiceType("valid", "d4", 278); //max 278
            List<string> vec8 = TxtReader.MakeAllInputsOfTargetDiceType("valid", "d6", 578); //max 578
            List<string> vec9 = TxtReader.MakeAllInputsOfTargetDiceType("valid", "d8", 218);   //max 218
            List<string> vec10 = TxtReader.MakeAllInputsOfTargetDiceType("valid", "d10", 246); //max 246
            List<string> vec11 = TxtReader.MakeAllInputsOfTargetDiceType("valid", "d12", 241); //max 241
            List<string> vec12 = TxtReader.MakeAllInputsOfTargetDiceType("valid", "d20", 478);	//max 478

            List<string> vectTrain = new List<string>();
            List<string> vectValid = new List<string>();

            //for (int i=0;i<1500;i++)
            //{
            //    vectTrain.Add(vec1[i]);
            //    vectTrain.Add(vec2[i]);
            //    vectTrain.Add(vec3[i]);
            //    vectTrain.Add(vec4[i]);
            //    vectTrain.Add(vec5[i]);
            //    vectTrain.Add(vec6[i]);
            //}

            //for (int i = 0; i < 200; i++)
            //{
            //    vectValid.Add(vec7[i]);
            //    vectValid.Add(vec8[i]);
            //    vectValid.Add(vec9[i]);
            //    vectValid.Add(vec10[i]);
            //    vectValid.Add(vec11[i]);
            //    vectValid.Add(vec12[i]);
            //}

            //for (int i =0;i<1500;i++)
            //    vectTrain.Add(vec1[i]);

            //for (int i = 0; i < 1500; i++)
            //    vectTrain.Add(vec2[i]);

            //for (int i = 0; i < 1500; i++)
            //    vectTrain.Add(vec3[i]);

            //for (int i = 0; i < 1500; i++)
            //    vectTrain.Add(vec4[i]);

            //for (int i = 0; i < 1500; i++)
            //    vectTrain.Add(vec5[i]);

            //for (int i = 0; i < 1500; i++)
            //    vectTrain.Add(vec6[i]);


            //for (int i = 0; i < 200; i++)
            //    vectValid.Add(vec7[i]);

            //for (int i = 0; i < 200; i++)
            //    vectValid.Add(vec8[i]);

            //for (int i = 0; i < 200; i++)
            //    vectValid.Add(vec9[i]);

            //for (int i = 0; i < 200; i++)
            //    vectValid.Add(vec10[i]);

            //for (int i = 0; i < 200; i++)
            //    vectValid.Add(vec11[i]);

            //for (int i = 0; i < 200; i++)
            //    vectValid.Add(vec12[i]);

            for (int i = 0; i < vec1.Count; i++)
                vectTrain.Add(vec1[i]);

            for (int i = 0; i < vec2.Count-1400; i++)
                vectTrain.Add(vec2[i]);

            for (int i = 0; i < vec3.Count; i++)
                vectTrain.Add(vec3[i]);

            for (int i = 0; i < vec4.Count; i++)
                vectTrain.Add(vec4[i]);

            for (int i = 0; i < vec5.Count; i++)
                vectTrain.Add(vec5[i]);

            for (int i = 0; i < vec6.Count-1200; i++)
                vectTrain.Add(vec6[i]);


            for (int i = 0; i < vec7.Count; i++)
                vectValid.Add(vec7[i]);

            for (int i = 0; i < vec8.Count; i++)
                vectValid.Add(vec8[i]);

            for (int i = 0; i < vec9.Count; i++)
                vectValid.Add(vec9[i]);

            for (int i = 0; i < vec10.Count; i++)
                vectValid.Add(vec10[i]);

            for (int i = 0; i < vec11.Count; i++)
                vectValid.Add(vec11[i]);

            for (int i = 0; i < vec12.Count; i++)
                vectValid.Add(vec12[i]);

            List<string> newListTrain = new List<string>();
            foreach (var str in vectTrain)
            {
                string temp="";
                for (int i=0;i<str.Length-1;i++)
                {
                    temp += str[i] + ",";
                }
                temp += str[str.Length - 1];
                newListTrain.Add(temp);
            }

            List<string> newListValid = new List<string>();
            foreach (var str in vectValid)
            {
                string temp = "";
                for (int i = 0; i < str.Length - 1; i++)
                {
                    temp += str[i] + ",";
                }
                temp += str[str.Length - 1];
                newListValid.Add(temp);
            }

            using (StreamWriter sw = new StreamWriter("train3.txt"))
            {
                foreach (var str in newListTrain)
                {
                    sw.WriteLine(str);

                }
            }
            using (StreamWriter sw = new StreamWriter("valid3.txt"))
            {
                foreach (var str in newListValid)
                {
                    sw.WriteLine(str);

                }
            }
        }
    }
}
