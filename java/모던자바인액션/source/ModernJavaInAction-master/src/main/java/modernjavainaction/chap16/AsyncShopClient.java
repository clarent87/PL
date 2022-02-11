package modernjavainaction.chap16;

import java.util.concurrent.Future;

public class AsyncShopClient {

  public static void main(String[] args) {

    AsyncShop shop = new AsyncShop("BestShop");

    long start = System.nanoTime();

    Future<Double> futurePrice = shop.getPrice("myPhone");

    long incocationTime = ((System.nanoTime() - start) / 1_000_000);

    System.out.println("Invocation returned after " + incocationTime + " msecs");

    // shop에서 값을 요청후 여기서 기타 다른 작업들을 할수 있음

    try {
      System.out.println("Price is " + futurePrice.get());
    } catch (Exception e) {
      throw new RuntimeException(e);
    }

    long retrivalTime = ((System.nanoTime() - start) / 1_000_000);

    System.out.println("Price returned after " + retrivalTime + " msecs");
  }

}
