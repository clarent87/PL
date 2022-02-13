package modernjavainaction.chap17;

import java.util.concurrent.Flow.Publisher;

public class Main {

  // 근데 왜 실행 후 종료가 안되지? -> 코드상 에러 나면 종료 되야 하는데..
  public static void main(String[] args) {
    getTemperatures("New York").subscribe(new TempSubscriber());
  } // 구독자 등록

  // TempSubscription는 퍼블리셔가 만들어서 제공하는 건가?? 그런거 같은데..
  private static Publisher<TempInfo> getTemperatures(String town) {
    return subscriber -> subscriber.onSubscribe(new TempSubscription(subscriber, town)); // 퍼블리셔가 구독자에게 TempSubscription 객체 전달
  }

}
