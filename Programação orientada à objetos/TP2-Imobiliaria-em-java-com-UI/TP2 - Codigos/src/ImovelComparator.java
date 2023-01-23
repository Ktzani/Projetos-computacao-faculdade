import java.util.Comparator;

public class ImovelComparator implements Comparator<Imovel>{
    public int compare (Imovel im1, Imovel im2){
        return (int)(im1.getValor() - im2.getValor());

    }
}
