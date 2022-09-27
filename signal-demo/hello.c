/*************************************************************************
        File Name: hello.c
        Author: dududu
        Mail: forxn@qq.com 
        Created Time: 2021年01月18日 星期一 10时10分34秒
 ************************************************************************/

#include<gtk/gtk.h>
//函数声明
void on_delete_event();
void on_button_clicked();
//定义单击次数统计
gint data_count = 1;

int main(int argc, char* argv[])
{
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(on_delete_event), NULL);

    gtk_window_set_title(GTK_WINDOW(window), "Hello World Test");
    gtk_window_set_default_size(GTK_WINDOW(window),500, 100);
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);

    gtk_container_set_border_width(GTK_CONTAINER(window),50);
    button = gtk_button_new_with_label("按下按钮将会显示一行信息：");
    //响应click事件
    g_signal_connect(G_OBJECT(button),"clicked",G_CALLBACK(on_button_clicked),(gpointer)data_count);
    gtk_container_add(GTK_CONTAINER(window),button);

    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();
    return FALSE;
}

void on_delete_event(GtkWidget *widget, GdkEvent* event, gpointer data)
{
     gtk_main_quit();
}
/*
 *实现单击显示Hello World 结果以及显示单击的次数data_count
*/
void on_button_clicked(GtkWidget *button, gpointer userdata)
{
    g_print("Hello,The test for 'Hello World'!");
    g_print("%d\n", data_count);
    data_count = data_count + 1;
}
