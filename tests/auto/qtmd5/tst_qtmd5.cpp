/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the test suite of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/


#include <QtTest/QtTest>

#ifdef QT_NO_SOLUTIONS
QTEST_NOOP_MAIN
#else

#include "qtmd5.h"

class tst_QtMD5: public QObject
{
    Q_OBJECT

private slots:
    void computeMD5_data();
    void computeMD5();
};

void tst_QtMD5::computeMD5_data()
{
    QTest::addColumn<QByteArray>("data");
    QTest::addColumn<QString>("expected");

    QTest::newRow("data0") << QByteArray("") << QString("d41d8cd98f00b204e9800998ecf8427e");
    QTest::newRow("data1") << QByteArray("a") << QString("0cc175b9c0f1b6a831c399e269772661");
    QTest::newRow("data2") << QByteArray("abc") << QString("900150983cd24fb0d6963f7d28e17f72");
    QTest::newRow("data3") << QByteArray("message digest") << QString("f96b697d7cb7938d525a2f31aaf161d0");
    QTest::newRow("data4") << QByteArray("abcdefghijklmnopqrstuvwxyz") << QString("c3fcd3d76192e4007dfb496cca67e13b");
    QTest::newRow("data5") << QByteArray("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789") << QString("d174ab98d277d9f5a5611c2c9f419d9f");
    QTest::newRow("data6") << QByteArray("12345678901234567890123456789012345678901234567890123456789012345678901234567890") << QString("57edf4a22be3c955ac49da2e2107b67a");
}

void tst_QtMD5::computeMD5()
{
    QFETCH(QByteArray, data);
    QFETCH(QString, expected);

    QCOMPARE(qtMD5(data), expected);
}

QTEST_MAIN(tst_QtMD5)
#include "tst_qtmd5.moc"
#endif
