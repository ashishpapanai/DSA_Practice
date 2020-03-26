public class huffmanClient
{
    public static void main(String[] args)
    {
        String s=args[0];
        huffmanED hed=new huffmanED("asdgvajdvmnasvcamnsvcasdaskmndbckasjbdcmanbscmsanbcmsnbcmsnbcmsnbcdmdsncmsbcmsnbcskgymnszdcvmzcvn");
        String encode=hed.Encoder(s);
        String decode=hed.Decoder(encode);
        System.out.println(encode+" -> "+decode);
        
    }
}