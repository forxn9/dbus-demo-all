/*************************************************************************
        File Name: event_demo.c
        Author: dududu
        Mail: forxn@qq.com 
        Created Time: 2021年01月18日 星期一 10时00分39秒
 ************************************************************************/
#include <gtk/gtk.h>

// 自訂Callback函式
void button_clicked_callback(GtkWidget *button, gpointer data) {
    g_print("clicked處理函式\n");
}

gboolean button_press_callback(
              GtkWidget *button, GdkEventButton *event, gpointer data) {
    g_print("button_press_event處理函式(%d, %d)\n", 
             (gint) event->x, (gint) event->y);

    return FALSE;
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *button;

    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "哈囉！GTK+！");

    button = gtk_button_new_with_label("按我");
    gtk_container_add(GTK_CONTAINER(window), button);

    g_signal_connect(GTK_OBJECT(button), "button_press_event",
                     G_CALLBACK(button_press_callback), NULL);
    g_signal_connect(GTK_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(GTK_OBJECT(button), "clicked",
                     G_CALLBACK(button_clicked_callback), NULL);

    gtk_widget_show(window);
    gtk_widget_show(button);

    gtk_main();

    return 0;
}
