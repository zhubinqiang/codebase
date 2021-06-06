/*
 * @file: ThreadCaseDemo.java
 * @author: ZhuBinQiang <zhu.binqiang@163.com>
 * @create time: 2021-06-06 23:36:06
 * @last modified: 2021-06-07 00:28:02
 * @description:
 */

class Info {
    private String name = "Tom";
    private String content = "Cat";
    private boolean flag = false;

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


    public synchronized void set(String name, String content) {
        if (!flag) {
            try {
                super.wait();
            } catch(InterruptedException e){
                e.printStackTrace();
            }
        }

        this.setName(name);

        try {
            Thread.sleep(300);
        } catch(InterruptedException e){
            e.printStackTrace();
        }

        this.setContent(content);

        flag = !flag;
        super.notify();
    }

    public synchronized void get() {
        if (flag) {
            try {
                super.wait();
            } catch(InterruptedException e){
                e.printStackTrace();
            }
        }

        try {
            Thread.sleep(300);
        } catch(InterruptedException e){
            e.printStackTrace();
        }

        System.out.println(this.getName() + "--->" +
                this.getContent());

        flag = !flag;
        super.notify();
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
                this.info.set("Tom", "Cat");
                flag = !flag;
            } else {
                this.info.set("Jerry", "Mouse");
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
            this.info.get();
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

