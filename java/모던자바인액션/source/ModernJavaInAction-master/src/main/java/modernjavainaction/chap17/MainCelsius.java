package modernjavainaction.chap17;

import java.util.concurrent.Flow.Publisher;

public class MainCelsius {

  public static void main(String[] args) {
    getCelsiusTemperatures("New York").subscribe(new TempSubscriber());
  }

  public static Publisher<TempInfo> getCelsiusTemperatures(String town) {
    return subscriber -> {
      TempProcessor processor = new TempProcessor(); // 얘가 대신 주제를 구독
      processor.subscribe(subscriber);
      processor.onSubscribe(new TempSubscription(processor, town)); // processor를 전달하네..
    };
  }

}
