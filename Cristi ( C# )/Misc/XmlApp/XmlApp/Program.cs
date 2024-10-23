using System.Xml;

namespace XmlApp
{
    class Program
    {
        static void Main(string[] args)
        {
            using (XmlReader reader = XmlReader.Create(@"E:\Cristi ( C# )\Misc\XmlApp\XmlApp\Books.xml"))
            {
                while (reader.Read())
                {
                    if (reader.IsStartElement())
                    {
                        switch (reader.Name.ToString())
                        {
                            case "author":
                                Console.WriteLine("The author of the book is : " + reader.ReadString());
                                break;

                            case "title":
                                Console.WriteLine("Title of the Book : " + reader.ReadString());
                                break;

                            case "price":
                                Console.WriteLine("Prise of the Book : " + reader.ReadString());
                                break;

                            case "description":
                                Console.WriteLine("Description of Book : " + reader.ReadString());
                                break;
                        }
                        Console.WriteLine("");
                    }
                }
            }
            Console.ReadKey();
        }
    }
}