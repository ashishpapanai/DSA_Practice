public class huffmanClientGIT{
    public static void main(String[] args){
        huffmanEDgit hed=new huffmanEDgit("asdgvajdvmnasvcamnsvcasdaskmndbckasjbdcmanbscmsanbcmsnbcmsnbcmsnbcdmdsncmsbcmsnbcskgymnszdcvmzcvn");
       
        String str=args[0];
       
        String encode=hed.Encoder(str);
        String decode=hed.Decoder(encode);

        System.out.println(encode+ " -> " + decode);
    }
}