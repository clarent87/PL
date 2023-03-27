# final

class 나 method에 붙일수 있고, 붙이면 상속, override 불가능 인듯.  
해당 키워드는 cpp에도 있었다. (class,method에 붙일수 있음)
  
안드로이드에서 변수에 final을 붙이면 상수풀에 들어가고(stack대신) 이러면 익명class나 람다에서도 해당 변수에 접근 가능.  
상수풀은 원래 사이즈가 제한적이었는데, jvm버전이 올라가면서 충분히 커진듯.(근데 gc가 돌지는 안는게 아닌가 싶다.)

객체 변수에 final이 붙으면 해당 변수의 참조는 처음 init된걸로 고정됨 <https://coding-factory.tistory.com/525>

- 퍼포먼스 테스트
  - <https://www.baeldung.com/java-final-performance>

## final vs non-final

bytecode에서 일단 큰 차이 없음.
> 혹시 List.of("a","b"); 라서?

- test code

  ```java
    @Getter
    @Setter
    public class ConstantPool {
        private final List<String> constPool = List.of("a","b");
        private List<String> nonConstPool = List.of("a","b");

    }

  ```

- byte code
  - 상수풀 확인
    - Java Class File의 구성 항목 중 하나인 Constant pool은 리터럴 상수 값을 저장하는 곳이다.  
    - 여기에는 String 뿐 아니라, 모든 종류의 숫자, 문자열, 식별자 이름, Class 및 Method 에 대한 참조와 같은 값이 포함된다.
    - Constant pool은 특정 상수에 대한 모든 인덱스 또는 참조를 16비트(type u2) 번호로 제공되며, 여기서 인덱스 값 1은 표의 첫 번째 상수를 나타낸다

  ```txt
    // 상수풀.
    ..                                                                                     
    #11 = InterfaceMethodref #12.#13        // java/util/List.of:(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;                      
    #12 = Class              #14            // java/util/List                                                                                
    #13 = NameAndType        #15:#16        // of:(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;                                     
    #14 = Utf8               java/util/List                                                                                                  
    #15 = Utf8               of                                                                                                              
    #16 = Utf8               (Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;     

    // ref에 차이가 없음.
    #17 = Fieldref           #18.#19        // com/example/redistest/javarecord/ConstantPool.constPool:Ljava/util/List;                      
    #18 = Class              #20            // com/example/redistest/javarecord/ConstantPool                                                 
    #19 = NameAndType        #21:#22        // constPool:Ljava/util/List;                                                                    
    #20 = Utf8               com/example/redistest/javarecord/ConstantPool                                                                   
    #21 = Utf8               constPool                                                                                                       
    
    #22 = Utf8               Ljava/util/List;                                                                                                
    #23 = Fieldref           #18.#24        // com/example/redistest/javarecord/ConstantPool.nonConstPool:Ljava/util/List;                   
    #24 = NameAndType        #25:#22        // nonConstPool:Ljava/util/List;                                                                 
    #25 = Utf8               nonConstPool                                                                                                    
    
    #26 = Utf8               Signature                                                                                                       
    #27 = Utf8               Ljava/util/List<Ljava/lang/String;>;                                                                            
    #28 = Utf8               Code                                                                                                            
    #29 = Utf8               LineNumberTable                                                                                                 
    #30 = Utf8               LocalVariableTable                                                                                              
    #31 = Utf8               this                                                                                                            
    #32 = Utf8               Lcom/example/redistest/javarecord/ConstantPool;                                                                 
    #33 = Utf8               getConstPool                                                                                                    
    #34 = Utf8               ()Ljava/util/List;                                                                                              
    #35 = Utf8               ()Ljava/util/List<Ljava/lang/String;>;                                                                          
    #36 = Utf8               getNonConstPool                                                                                                 
    #37 = Utf8               setNonConstPool                                                                                                 
    #38 = Utf8               (Ljava/util/List;)V                                                                                             
    #39 = Utf8               LocalVariableTypeTable                                                                                          
    #40 = Utf8               MethodParameters                                                                                                
    #41 = Utf8               (Ljava/util/List<Ljava/lang/String;>;)V                                                                         
    #42 = Utf8               SourceFile                                                                                                      
    #43 = Utf8               ConstantPool.java                                                                                               
  {                                                                                                                                          
    private final java.util.List<java.lang.String> constPool;                                                                                
      descriptor: Ljava/util/List;                                                                                                           
      flags: (0x0012) ACC_PRIVATE, ACC_FINAL                                                                                                 
      Signature: #27                          // Ljava/util/List<Ljava/lang/String;>;                                                        
                                                                                                                                            
    private java.util.List<java.lang.String> nonConstPool;                                                                                   
      descriptor: Ljava/util/List;                                                                                                           
      flags: (0x0002) ACC_PRIVATE                                                                                                            
      Signature: #27                          // Ljava/util/List<Ljava/lang/String;>;                                                        
                                                                                                                                            
    public com.example.redistest.javarecord.ConstantPool();                                                                                  
      descriptor: ()V                                                                                                                        
      flags: (0x0001) ACC_PUBLIC                                                                                                             
      Code:                                                                                                                                  
        stack=3, locals=1, args_size=1                                                                                                       
          0: aload_0                                                                                                                        
          1: invokespecial #1                  // Method java/lang/Object."<init>":()V                                                      
          // final 필드 초기화
          4: aload_0                                                                                                                        
          5: ldc           #7                  // String a                                                                                  
          7: ldc           #9                  // String b                                                                                  
          9: invokestatic  #11                 // InterfaceMethod java/util/List.of:(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;  
          12: putfield      #17                 // Field constPool:Ljava/util/List;                                                          
          // final 아닌 필드 초기화
          15: aload_0                                                                                                                        
          16: ldc           #7                  // String a                                                                                  
          18: ldc           #9                  // String b                                                                                  
          20: invokestatic  #11                 // InterfaceMethod java/util/List.of:(Ljava/lang/Object;Ljava/lang/Object;)Ljava/util/List;  
          23: putfield      #23                 // Field nonConstPool:Ljava/util/List;                                                       
          26: return                                                                                                                         
        LineNumberTable:                                                                                                                     
          line 10: 0                                                                                                                         
          line 11: 4                                                                                                                         
          line 12: 15                                                                                                                        
        LocalVariableTable:                                                                                                                  
          Start  Length  Slot  Name   Signature                                                                                              
              0      27     0  this   Lcom/example/redistest/javarecord/ConstantPool;                                                        

  ```

- 참조
  - <https://blog.breakingthat.com/2018/12/21/java-constant-pool%EA%B3%BC-string-pool/>
  - <https://jiwondev.tistory.com/114>
