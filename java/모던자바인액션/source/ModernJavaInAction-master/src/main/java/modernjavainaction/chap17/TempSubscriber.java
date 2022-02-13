package modernjavainaction.chap17;

import java.util.concurrent.Flow.Subscriber;
import java.util.concurrent.Flow.Subscription;

public class TempSubscriber implements Subscriber<TempInfo> {

  private Subscription subscription;

  @Override
  public void onSubscribe(Subscription subscription) {
    this.subscription = subscription;
    // 아.. 이거는 subscriber가 data를 요청해서 받아가는 형태네..
    // 그럼 퍼블리셔는 onNext를 호출해서 data 전달.
    subscription.request(1); // pubilsher에게 data를 한개만 달라는 요청?
  }

  @Override
  public void onNext(TempInfo tempInfo) {
    System.out.println(tempInfo);
    subscription.request(1);
  }

  @Override
  public void onError(Throwable t) {
    System.err.println(t.getMessage());
  }

  @Override
  public void onComplete() {
    System.out.println("Done!");
  }

}
