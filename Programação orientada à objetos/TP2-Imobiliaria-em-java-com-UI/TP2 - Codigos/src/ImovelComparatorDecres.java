import java.util.Comparator;

public class ImovelComparatorDecres implements Comparator<Imovel>{
    public int compare (Imovel im1, Imovel im2){
        return (int)(im2.getValor() - im1.getValor());

    }
}