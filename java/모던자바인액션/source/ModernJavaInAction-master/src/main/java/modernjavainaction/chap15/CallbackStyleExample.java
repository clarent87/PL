package modernjavainaction.chap15;

import java.util.function.IntConsumer;
// 475p
public class CallbackStyleExample {

  public static void main(String[] args) {

    int x = 1337;
    Result result = new Result();

    f(x, (int y) -> {
      result.left = y;
      System.out.println((result.left + result.right));
    });

    g(x, (int z) -> {
      result.right = z;
      System.out.println((result.left + result.right));
    });
  }

  private static class Result {
    private int left;
    private int right;
  }

  private static void f(int x, IntConsumer dealWithResult) {
    dealWithResult.accept(Functions.f(x));
  } // f(x) 계산후 람다 실행

  private static void g(int x, IntConsumer dealWithResult) {
    dealWithResult.accept(Functions.g(x));
  }

}
