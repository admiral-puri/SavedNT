class Authenticator
{
 String uid, pass;
 
 Authenticator(String u, String p)
 {
   uid = u;
   pass = p;
 }

 boolean match(String u, String p)
 {
   System.out.println("to match : ");
   System.out.println(uid + ":" + u);
   System.out.println(pass + ":" + p);
   return uid.equalsIgnoreCase(u) && pass.equals(p);
 }
}//Authenticator

class Securer extends Authenticator
{
  String key;
  Securer(String u, String p, String k) 
  {
    super(u,p);//invoking Authenticator(u,p);
    key = k;
    pass = encrypt(p);//update the password
    
  }

  String encrypt(String p)
  {//p = "tiger"
   //key = "this is a sample key"
   int addition = 0;
   int i, len;
   len = key.length();
   for(i =0 ; i < len; i++)
     addition += (int)key.charAt(i);
   

   len = p.length();
   String enc_pass= "";
   for(i =0 ; i < len; i++)
    enc_pass = enc_pass + (char) ((int)p.charAt(i) ^ addition) ;

   return enc_pass;
  }

  boolean match(String u, String p)
  {
    return super.match(u, encrypt(p));
  } 
}//Securer

class Email
{
  Authenticator au;  

  void sendMail()
  {
   System.out.println("Sending Mail");
  }

  void receiveMail()
  {
   System.out.println("Receiving Mail");
  }

  void signup(String u, String p)
  {
    au = new Authenticator(u,p);
  }

  boolean login(String u, String p)
  {
   return au.match(u,p);
  }
}


class Inherit_or_Not
{
 public static void main(String args[])
 {
   System.out.println("-----Inheriting to Enhance------");
   Securer sc = new Securer("tiger", "unbreakable", "this is a sample key");
   if(sc.match("tiger", "unbreakaBle"))
    System.out.println("True");
   else
    System.out.println("False");
   System.out.println("-----------------------------------");

   System.out.println("-----Create Object to Utilize------");
   Email em = new Email();
   em.signup("Vikas", "909090");
   if(em.login("Vikas", "909090"))
   {
     em.sendMail();
     em.receiveMail();
   }
   else
     System.out.println("Login Failed");
   System.out.println("-----------------------------------");

 }
}