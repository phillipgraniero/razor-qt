#ifndef RAZORTASK_H
#define RAZORTASK_H
#include "defs.h"


class RazorBarTask;
#include "razorplugin.h"

/**
 * @file razortask.h
 * @brief declares class Razortask and Razortaskmanager
 * @author Christopher "VdoP" Regali
 */


/**
 * @brief this is a single running task - element of the Razortaskmanager
 */



class RazorTask
{
public:
    RazorTask(Window _id, int _screen);
    ~RazorTask();
    Window get_client()
    {
        return client;
    }
    void setTitle(QString _title)
    {
        title = _title;
    }
    QString getTitle();
    void toogleMin();
    void setFullscreen();
    bool getIcon(QPixmap& _pixm);
    void settoDesktop(int _newdesk);
    bool isHidden();
    bool isActive();
    void raiseMe();
    int getDesktop()
    {
        return desktop;
    }
private:
    bool hidden;
    int desktop;
    bool hasIcon;
    QPixmap clientIcon;
    Window client;
    int onScreen;
    QString title;
    int state;
};

/**
 * @brief this manages the running tasks
 */

class RazorTaskManager : public RazorPlugin
{
    Q_OBJECT
public:
    RazorTaskManager(RazorBar * panel, QWidget * parent, const QString & name);
    ~RazorTaskManager();
    bool handleEvent(XEvent* );

    int widthForHeight(int h);
    int heightForWidth(int w);
    RazorPlugin::RazorPluginSizing sizePriority();

private:
    RazorBarTask* gui;
    void updateMap();

    QMap <Window, RazorTask*> clientList;
};

extern "C" RazorPlugin* init(RazorBar* panel, QWidget* parent, const QString & name);

#endif
