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
#ifndef QBIC_H
#define QBIC_H

#include "QtCore/qhash.h"
#include "QtCore/qlist.h"
#include "QtCore/qpair.h"
#include "QtCore/qregexp.h"
#include "QtCore/qstring.h"
#include "QtCore/qstringlist.h"

QT_FORWARD_DECLARE_CLASS(QByteArray)

class QBic
{
public:
    struct Info
    {
        QHash<QString, int> classSizes;
        QHash<QString, QStringList> classVTables;
    };

    struct VTableDiff
    {
        QList<QPair<QString, QString> > reimpMethods;
        QList<QPair<QString, QString> > modifiedVTables;
        QStringList addedVTables;
        QStringList removedVTables;
    };

    struct SizeDiff
    {
        QStringList mismatch;
        QStringList added;
        QStringList removed;
    };

    void addBlacklistedClass(const QString &wildcard);
    void removeBlacklistedClass(const QString &wildcard);
    bool isBlacklisted(const QString &className) const;

    Info parseOutput(const QByteArray &ba) const;
    Info parseFile(const QString &fileName) const;

    VTableDiff diffVTables(const Info &oldLib, const Info &newLib) const;
    SizeDiff diffSizes(const Info &oldLib, const Info &newLib) const;

private:
    QList<QRegExp> blackList;
};

#endif
