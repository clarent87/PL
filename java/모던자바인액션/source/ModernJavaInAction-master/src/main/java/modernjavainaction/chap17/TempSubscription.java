package modernjavainaction.chap17;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Flow.Subscriber;
import java.util.concurrent.Flow.Subscription;

public class TempSubscription implements Subscription {

  private static final ExecutorService executor = Executors.newSingleThreadExecutor();

  private final Subscriber<? super TempInfo> subscriber;
  private final String town;

  public TempSubscription(Subscriber<? super TempInfo> subscriber, String town) {
    this.subscriber = subscriber;
    this.town = town;
  }

  // 원래 이렇게 쓰는건가?
  // 역압력? 을 위한 기능인데, 그냥 예시인듯. 실제로는 이렇게 쓰는게 아닌듯. (553)
  @Override
  public void request(long n) {
    executor.submit(() -> {
      for (long i = 0L; i < n; i++) {
        try {
          subscriber.onNext(TempInfo.fetch(town));
        } catch (Exception e) {
          subscriber.onError(e);
          break;
        }
      }
    });
  }

  @Override
  public void cancel() {
    subscriber.onComplete();
  }

}
