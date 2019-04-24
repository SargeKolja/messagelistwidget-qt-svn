#ifndef MESSAGELISTWIDGET_H
#define MESSAGELISTWIDGET_H

/**
 * Project "MessageListWidget for Qt"
 *
 * MessageListWidget.cpp
 * 
 * Just want to see your debugs/logs in a QtWidget, like QListView? 
 * Want to start with Qt, and like to work together, bring your ideas and code?
 *
 * You are welcome, here we go!
 *
 * This is mostly a simplified implementation of a line-by-line list window which
 * can reside at the bottom of your application and show what happens inside, or 
 * give the user some journal information. All the stuff a lot of communication
 * related graphical UI programs are doing since years.
 *
 * Also want to have this?
 *
 * You simply add this two files to your project and bind its SLOT with a SIGNAL
 * Basically, you just need to connect your SIGNAL to one of the four SLOTs.
 * best to start with the simplest.
 * 
 * copyright 2019 Sergeant Kolja, GERMANY
 * 
 * distributed under the terms of the 2-clause license also known as "Simplified BSD License" or "FreeBSD License"
 * License is compatible with GPL and LGPL
 */ 

#include <QWidget>
#include <QListWidget>

#include "rDebugCodeloc.h"

class MessageListWidget : public QListWidget //public QWidget
{
  Q_OBJECT
public:
  explicit MessageListWidget( QWidget *parent = nullptr, const QString& objectName="MessageList", int initialMaxLevel = 4 ); // TODO: replace 4 with some enum, but less sticky than using rDebug_Level
  virtual ~MessageListWidget();

public:
  void paintMessage( const QDateTime& Time, int Lvl, uint64_t LogId, const QString& line );
  //void setToolTip(const QString& ToolTip);
  QString getLevelName( int Level ) const;
  QString getDateTimeStr( const QDateTime& Time ) const;
  QString getLogIdStr( uint64_t LogId ) const;

//signals:

public slots:
  void on_logline( const FileLineFunc_t& CodeLocation, const QDateTime& Time, int Level, uint64_t LogId, const QString& line );
  void on_logline( const QDateTime& Time, int Level, uint64_t LogId, const QString& line );
  void on_logline( const QDateTime& Time, int Level, const QString& line );
  void on_logline( int Level, const QString& line );

private:
  QListWidget* mpListing;
  int          mMaxLevel;
  bool         mWithDate;
  bool         mWithLevel;
  bool         mWithID;
};

#endif // MESSAGELISTWIDGET_H
