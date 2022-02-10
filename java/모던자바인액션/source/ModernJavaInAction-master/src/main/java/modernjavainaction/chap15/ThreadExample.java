package modernjavainaction.chap15;

import static modernjavainaction.chap15.Functions.f;
import static modernjavainaction.chap15.Functions.g;

class ThreadExample {

  // 아래 예제 보다는 future를 이용하는 것이 코드가 더 깔끔한 장점이 있다.
  public static void main(String[] args) throws InterruptedException {
    int x = 1337;
    Result result = new Result();

    Thread t1 = new Thread(() -> {
      result.left = f(x);
    });
    Thread t2 = new Thread(() -> {
      result.right = g(x);
    });
    t1.start();
    t2.start();
    t1.join();
    t2.join();
    System.out.println(result.left + result.right);
  }

  private static class Result {
    private int left;
    private int right;
  }

}
