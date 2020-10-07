package steganography;

public class Main 
{
  public static void main(String[] args) 
  {
    try
    {
      Embedder emb = new Embedder("this is good", "D:/Rahul classes/Java/MiniProject/crop.jpg", "D:/Rahul classes/Java/MiniProject/a.jpg", "D:/Rahul classes/Java/MiniProject/ppp.png");
      emb.embed();
      Extractor ext = new Extractor("this is good", "D:/Rahul classes/Java/MiniProject/ppp.png", "D:/Rahul classes/Java/MiniProject/result");
      ext.extract();
      
    }
    catch(Exception ex)
    {
      System.out.println("Err: " + ex);
    }
  }
}
