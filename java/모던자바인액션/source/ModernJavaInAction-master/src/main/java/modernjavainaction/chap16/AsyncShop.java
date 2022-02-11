package modernjavainaction.chap16;

import static modernjavainaction.chap16.Util.delay;
import static modernjavainaction.chap16.Util.format;

import java.util.Random;
import java.util.concurrent.CompletableFuture;
import java.util.concurrent.Future;

public class AsyncShop {

  private final String name;
  private final Random random;

  public AsyncShop(String name) {
    this.name = name;
    random = new Random(name.charAt(0) * name.charAt(1) * name.charAt(2));
  }

  public Future<Double> getPrice(String product) {
/*
    CompletableFuture<Double> futurePrice = new CompletableFuture<>();
    new Thread(() -> {
      try {
        double price = calculatePrice(product);
        futurePrice.complete(price); // future에 값 세팅
      } catch (Exception ex) {
        futurePrice.completeExceptionally(ex); // 예외를 future로 전달함
      }
    }).start();
    return futurePrice;
*/
    return CompletableFuture.supplyAsync(() -> calculatePrice(product));
  }

  private double calculatePrice(String product) {
    delay();
    if (true) {
      throw new RuntimeException("product not available");
    }
    return format(random.nextDouble() * product.charAt(0) + product.charAt(1));
  }

}
