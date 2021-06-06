/*
 * @file: ThreadCaseDemo.java
 * @author: ZhuBinQiang <zhu.binqiang@163.com>
 * @create time: 2021-06-06 23:36:06
 * @last modified: 2021-06-07 00:28:27
 * @description:
 */

class Info {
    private String name = "Tom";
    private String content = "Cat";

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return this.name;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public String getContent() {
        return this.content;
    }
}


class Producer implements Runnable {
    private Info info;

    public Producer(Info info) {
        this.info = info;
    }

    @Override
    public void run() {
        boolean flag = false;
        for (int i=0; i<50; i++) {
            if(flag) {
                this.info.setName("Tom");

                try {
                    Thread.sleep(90);
                } catch(InterruptedException e){
                    e.printStackTrace();
                }

                this.info.setContent("Cat");
                flag = !flag;
            } else {
                this.info.setName("Jerry");

                try {
                    Thread.sleep(90);
                } catch(InterruptedException e){
                    e.printStackTrace();
                }

                this.info.setContent("Mouse");
                flag = !flag;
            }

        }
    }
}

class Consumer implements Runnable {
    private Info info;

    public Consumer(Info info) {
        this.info = info;
    }

    @Override
    public void run() {
        boolean flag = false;
        for (int i=0; i<50; i++) {
            try {
                Thread.sleep(90);
            } catch(InterruptedException e){
                e.printStackTrace();
            }

            System.out.println(this.info.getName() + "--->" +
                    this.info.getContent());
        }
    }
}


public class ThreadCaseDemo {
    public static void main(String[] args) {
        Info info = new Info();
        Producer pro = new Producer(info);
        Consumer con = new Consumer(info);
        new Thread(pro).start();
        new Thread(con).start();
    }
}

