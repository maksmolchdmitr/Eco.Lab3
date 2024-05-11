/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoLab1
 * </сводка>
 *
 * <описание>
 *   Данный исходный код описывает реализацию интерфейсов CEcoLab1
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoSystem1.h"
#include "IEcoInterfaceBus1.h"
#include "IEcoInterfaceBus1MemExt.h"
#include "IEcoConnectionPointContainer.h"
#include "IEcoEnumConnections.h"

#include "CEcoLab1.h"
#include "CEcoLab1EnumConnectionPoints.h"

#include <stdbool.h>

/*
 *
 * <сводка>
 *   Функция QueryInterface
 * </сводка>
 *
 * <описание>
 *   Функция QueryInterface для интерфейса IEcoLab1
 * </описание>
 *
 */
int16_t CEcoLab1_QueryInterface(/* in */ struct IEcoLab1 *me, /* in */ const UGUID *riid, /* out */ void **ppv) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;

    /* Проверка указателей */
    if (me == 0 || ppv == 0) {
        return -1;
    }

    /* Проверка и получение запрошенного интерфейса */
    if (IsEqualUGUID(riid, &IID_IEcoLab1)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 * )
        pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer)) {
        *ppv = &pCMe->m_pVTblIEcoConnectionPointContainter;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 * )
        pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 * )
        pCMe);
    } else {
        *ppv = 0;
        return -1;
    }
    return 0;
}

/*
 *
 * <сводка>
 *   Функция AddRef
 * </сводка>
 *
 * <описание>
 *   Функция AddRef для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t CEcoLab1_AddRef(/* in */ struct IEcoLab1 *me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;

    /* Проверка указателя */
    if (me == 0) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция Release
 * </сводка>
 *
 * <описание>
 *   Функция Release для интерфейса IEcoLab1
 * </описание>
 *
 */
uint32_t CEcoLab1_Release(/* in */ struct IEcoLab1 *me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;

    /* Проверка указателя */
    if (me == 0) {
        return -1;
    }

    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoLab1((IEcoLab1 * )
        pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

/*
 *
 * <сводка>
 *   Функция MyFunction
 * </сводка>
 *
 * <описание>
 *   Функция
 * </описание>
 *
 */
int16_t CEcoLab1_ShellSortShellStep(/* in */ struct IEcoLab1 *me, /* in */ void *base, size_t number, size_t width,
                                             int (*cmp)(const void *, const void *)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t index = 0;
    int step = 0;
    int i = 0;
    int j = 0;
    char *charBase = base;

    /* Проверка указателей */
    if (me == 0 || base == 0) {
        return -1;
    }

    for (step = number / 2; step > 0; step /= 2) {
        for (i = step; i < number; ++i) {
            for (j = i - step; j >= 0 && cmp(charBase + j * width, charBase + (j + step) * width) > 0; j -= step) {
                swap(charBase + j * width, charBase + (j + step) * width, width);
            }
        }
    }

    return 0;
}

int16_t CEcoLab1_ShellSortHibbardStep(/* in */ struct IEcoLab1 *me, /* in */ void *base, size_t number, size_t width,
                                               int (*cmp)(const void *, const void *)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t index = 0;
    int step = 0;
    int var = 0;
    int i = 0;
    int j = 0;
    char *charBase = base;

    /* Проверка указателей */
    if (me == 0 || base == 0) {
        return -1;
    }

    var = 1;
    while (var * 2 - 1 < number) {
        var *= 2;
    }
    step = var - 1;

    for (; step > 0; step = (step + 1) / 2 - 1) {
        for (i = step; i < number; ++i) {
            for (j = i - step; j >= 0 && cmp(charBase + j * width, charBase + (j + step) * width) > 0; j -= step) {
                swap(charBase + j * width, charBase + (j + step) * width, width);
            }
        }
    }

    return 0;
}

int16_t CEcoLab1_ShellSortKnuthStep(/* in */ struct IEcoLab1 *me, /* in */ void *base, size_t number, size_t width,
                                             int (*cmp)(const void *, const void *)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t index = 0;
    int step = 0;
    int var = 0;
    int i = 0;
    int j = 0;
    char *charBase = base;

    /* Проверка указателей */
    if (me == 0 || base == 0) {
        return -1;
    }

    var = 1;
    while ((var * 3 - 1) / 2 < (number / 3)) {
        var *= 3;
    }
    step = (var - 1) / 2;

    for (; step > 0; step = (((step * 2 + 1) / 3) - 1) / 2) {
        for (i = step; i < number; ++i) {
            for (j = i - step; j >= 0 && cmp(charBase + j * width, charBase + (j + step) * width) > 0; j -= step) {
                swap(charBase + j * width, charBase + (j + step) * width, width);
            }
        }
    }

    return 0;
}


int16_t ShellSortShellStep_WithLog(/* in */ struct IEcoLab1 *me, /* in */ void *base, size_t number, size_t width,
                                            int (*cmp)(const void *, const void *), void (*print)(const void *),
                                            void (*print_array)(void *, size_t)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t index = 0;
    int step = 0;
    int i = 0;
    int j = 0;
    char *charBase = base;

    /* Проверка указателей */
    if (me == 0 || base == 0) {
        return -1;
    }

    for (step = number / 2; step > 0; step /= 2) {
        for (i = step; i < number; ++i) {
            for (j = i - step; j >= 0 && cmp(charBase + j * width, charBase + (j + step) * width) > 0; j -= step) {
                swap_with_log(me, charBase + j * width, charBase + (j + step) * width, width, print);
                change_array_with_log(me, base, number, print_array);
            }
        }
    }

    return 0;
}

int16_t ShellSortHibbardStep_WithLog(/* in */ struct IEcoLab1 *me, /* in */ void *base, size_t number, size_t width,
                                              int (*cmp)(const void *, const void *), void (*print)(const void *),
                                              void (*print_array)(void *, size_t)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t index = 0;
    int step = 0;
    int var = 0;
    int i = 0;
    int j = 0;
    char *charBase = base;

    /* Проверка указателей */
    if (me == 0 || base == 0) {
        return -1;
    }

    var = 1;
    while (var * 2 - 1 < number) {
        var *= 2;
    }
    step = var - 1;

    for (; step > 0; step = (step + 1) / 2 - 1) {
        for (i = step; i < number; ++i) {
            for (j = i - step; j >= 0 && cmp(charBase + j * width, charBase + (j + step) * width) > 0; j -= step) {
                swap_with_log(me, charBase + j * width, charBase + (j + step) * width, width, print);
                change_array_with_log(me, base, number, print_array);
            }
        }
    }

    return 0;
}

int16_t ShellSortKnuthStep_WithLog(/* in */ struct IEcoLab1 *me, /* in */ void *base, size_t number, size_t width,
                                            int (*cmp)(const void *, const void *), void (*print)(const void *),
                                            void (*print_array)(void *, size_t)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t index = 0;
    int step = 0;
    int var = 0;
    int i = 0;
    int j = 0;
    char *charBase = base;

    /* Проверка указателей */
    if (me == 0 || base == 0) {
        return -1;
    }

    var = 1;
    while ((var * 3 - 1) / 2 < (number / 3)) {
        var *= 3;
    }
    step = (var - 1) / 2;

    for (; step > 0; step = (((step * 2 + 1) / 3) - 1) / 2) {
        for (i = step; i < number; ++i) {
            for (j = i - step; j >= 0 && cmp(charBase + j * width, charBase + (j + step) * width) > 0; j -= step) {
                swap_with_log(me, charBase + j * width, charBase + (j + step) * width, width, print);
                change_array_with_log(me, base, number, print_array);
            }
        }
    }

    return 0;
}

int16_t CEcoLab1_PushEvent_OnSwap(/* in */ struct IEcoLab1Events *me, void *a, void *b, void (*print)(const void *)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t result = 0;
    uint32_t count = 0;
    uint32_t index = 0;
    IEcoEnumConnections * pEnum = 0;
    IEcoLab1Events * pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint * )
        pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint * )
        pCMe->m_pISinkCP, &pEnum);
        if ((result == 0) && (pEnum != 0)) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void **) &pIEvents);
                if ((result == 0) && (pIEvents != 0)) {
                    result = pIEvents->pVTbl->OnSwap(pIEvents, a, b, print);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

int16_t CEcoLab1_PushEvent_OnChangeArray(/* in */ struct IEcoLab1 *me, void *base, size_t number,
                                                  void (*print_array)(void *, size_t)) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    int16_t result = 0;
    uint32_t count = 0;
    uint32_t index = 0;
    IEcoEnumConnections * pEnum = 0;
    IEcoLab1Events * pIEvents = 0;
    EcoConnectionData cd;

    if (me == 0) {
        return -1;
    }

    if (pCMe->m_pISinkCP != 0) {
        result = ((IEcoConnectionPoint * )
        pCMe->m_pISinkCP)->pVTbl->EnumConnections((IEcoConnectionPoint * )
        pCMe->m_pISinkCP, &pEnum);
        if ((result == 0) && (pEnum != 0)) {
            while (pEnum->pVTbl->Next(pEnum, 1, &cd, 0) == 0) {
                result = cd.pUnk->pVTbl->QueryInterface(cd.pUnk, &IID_IEcoLab1Events, (void **) &pIEvents);
                if ((result == 0) && (pIEvents != 0)) {
                    result = pIEvents->pVTbl->OnChangeArray(pIEvents, base, number, print_array);
                    pIEvents->pVTbl->Release(pIEvents);
                }
                cd.pUnk->pVTbl->Release(cd.pUnk);
            }
            pEnum->pVTbl->Release(pEnum);
        }
    }
    return result;
}

void change_array_with_log(/* in */ struct IEcoLab1 *me, void *base, size_t number,
                                    void (*print_array)(void *, size_t)) {
    CEcoLab1_PushEvent_OnChangeArray(me, base, number, print_array);
}

void swap_with_log(/* in */ struct IEcoLab1 *me, void *a, void *b, size_t size, void (*print)(const void *)) {
    size_t i = 0;
    char buffer[size]; // Временный буфер для обмена значений
    char *pa = (char *) a;
    char *pb = (char *) b;

    CEcoLab1_PushEvent_OnSwap(me, a, b, print);

    for (i = 0; i < size; i++) {
        buffer[i] = pa[i];
        pa[i] = pb[i];
        pb[i] = buffer[i];
    }
}

void swap(void *a, void *b, size_t size) {
    size_t i = 0;
    char buffer[size]; // Временный буфер для обмена значений
    char *pa = (char *) a;
    char *pb = (char *) b;

    for (i = 0; i < size; i++) {
        buffer[i] = pa[i];
        pa[i] = pb[i];
        pb[i] = buffer[i];
    }
}

/*
 *
 * <сводка>
 *   Функция Init
 * </сводка>
 *
 * <описание>
 *   Функция инициализации экземпляра
 * </описание>
 *
 */
int16_t initCEcoLab1(/*in*/ struct IEcoLab1 *me, /* in */ struct IEcoUnknown *pIUnkSystem) {
    CEcoLab1 *pCMe = (CEcoLab1 *) me;
    IEcoInterfaceBus1 *pIBus = 0;
    int16_t result = -1;

    /* Проверка указателей */
    if (me == 0) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1 *) pIUnkSystem;

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pCMe->m_pISys->pVTbl->QueryInterface(pCMe->m_pISys, &IID_IEcoInterfaceBus1, (void **) &pIBus);

    /* Проверка указателей */
    if (me == 0) {
        return result;
    }

    /* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = (IEcoSystem1 *) pIUnkSystem;

    /* Создание точки подключения */
    result = createCEcoLab1ConnectionPoint((IEcoUnknown * )
    pCMe->m_pISys, &pCMe->m_pVTblIEcoConnectionPointContainter, &IID_IEcoLab1Events, (IEcoConnectionPoint * *) &
                                                                                     ((pCMe)->m_pISinkCP));
    if (result == 0 && pCMe->m_pISinkCP != 0) {
        result = 0;
    }

    /* Освобождение */
    pIBus->pVTbl->Release(pIBus);

    return result;
}

/* Create Virtual Table IEcoLab1 */
IEcoLab1VTbl g_x277FC00C35624096AFCFC125B94EEC90VTbl = {
        CEcoLab1_QueryInterface,
        CEcoLab1_AddRef,
        CEcoLab1_Release,
        CEcoLab1_ShellSortShellStep,
        CEcoLab1_ShellSortHibbardStep,
        CEcoLab1_ShellSortKnuthStep,
        ShellSortShellStep_WithLog,
        ShellSortHibbardStep_WithLog,
        ShellSortKnuthStep_WithLog
};

int16_t CEcoLab1_IEcoConnectionPointContainer_QueryInterface(/* in */ struct IEcoConnectionPointContainer *me, /* in */
                                                                      const UGUID *riid, /* out */ void **ppv) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *));
    if (me == 0 || ppv == 0) {
        return -1;
    }
    if (IsEqualUGUID(riid, &IID_IEcoLab1)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *) pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoConnectionPointContainer)) {
        *ppv = &pCMe->m_pVTblIEcoConnectionPointContainter;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *) pCMe);
    } else if (IsEqualUGUID(riid, &IID_IEcoUnknown)) {
        *ppv = &pCMe->m_pVTblIEcoLab1;
        pCMe->m_pVTblIEcoLab1->AddRef((IEcoLab1 *) pCMe);
    } else {
        *ppv = 0;
        return -1;
    }

    return 0;
}

uint32_t CEcoLab1_IEcoConnectionPointContainer_AddRef(/* in */ struct IEcoConnectionPointContainer *me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *));

    if (me == 0) {
        return -1;
    }

    return ++pCMe->m_cRef;
}

uint32_t CEcoLab1_IEcoConnectionPointContainer_Release(/* in */ struct IEcoConnectionPointContainer *me) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *));

    /* Проверка указателей */
    if (me == 0) {
        return -1;
    }
    /* Уменьшение счетчика ссылок на компонент */
    --pCMe->m_cRef;

    /* В случае обнуления счетчика, освобождение данных экземпляра */
    if (pCMe->m_cRef == 0) {
        deleteCEcoLab1((IEcoLab1 *) pCMe);
        return 0;
    }
    return pCMe->m_cRef;
}

int16_t CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints(/* in */ struct IEcoConnectionPointContainer *me,
        /* out */ struct IEcoEnumConnectionPoints **ppEnum) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *));
    int16_t result = 0;

    if (me == 0 || ppEnum == 0) {
        return -1;
    }

    result = createCEcoLab1EnumConnectionPoints((IEcoUnknown * )
    pCMe->m_pISys, &pCMe->m_pISinkCP->m_pVTblICP, ppEnum);

    return result;
}

int16_t
CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint(/* in */ struct IEcoConnectionPointContainer *me, /* in */
                                                                   const UGUID *riid, /* out */
                                                                   struct IEcoConnectionPoint **ppCP) {
    CEcoLab1 *pCMe = (CEcoLab1 *) ((uint64_t) me - sizeof(struct IEcoLab1 *));
    int16_t result = 0;

    /* Проверка указателей */
    if (me == 0 || ppCP == 0) {
        return -1;
    }

    if (!IsEqualUGUID(riid, &IID_IEcoLab1Events)) {
        *ppCP = 0;
        /* CONNECT_E_NOCONNECTION */
        return -1;
    }

    if (pCMe->m_pISinkCP == 0) {
        /* E_FAIL */
        return -1;
    }

    pCMe->m_pISinkCP->m_pVTblICP->AddRef(&pCMe->m_pISinkCP->m_pVTblICP);
    *ppCP = &pCMe->m_pISinkCP->m_pVTblICP;

    return 0;
}

/* Create Virtual Table IEcoConnectionPointContainer */
IEcoConnectionPointContainerVTbl g_x0000000500000000C000000000000046VTblCPC = {
        CEcoLab1_IEcoConnectionPointContainer_QueryInterface,
        CEcoLab1_IEcoConnectionPointContainer_AddRef,
        CEcoLab1_IEcoConnectionPointContainer_Release,
        CEcoLab1_IEcoConnectionPointContainer_EnumConnectionPoints,
        CEcoLab1_IEcoConnectionPointContainer_FindConnectionPoint
};

/*
 *
 * <сводка>
 *   Функция Create
 * </сводка>
 *
 * <описание>
 *   Функция создания экземпляра
 * </описание>
 *
 */
int16_t createCEcoLab1(/* in */ IEcoUnknown
                                *pIUnkSystem, /* in */ IEcoUnknown *pIUnkOuter, /* out */ IEcoLab1
                                **ppIEcoLab1) {
    int16_t result = -1;
    IEcoSystem1 *pISys = 0;
    IEcoInterfaceBus1 *pIBus = 0;
    IEcoInterfaceBus1MemExt *pIMemExt = 0;
    IEcoMemoryAllocator1 *pIMem = 0;
    CEcoLab1 *pCMe = 0;
    UGUID *rcid = (UGUID * ) & CID_EcoMemoryManager1;

/* Проверка указателей */
    if (ppIEcoLab1 == 0 || pIUnkSystem == 0) {
        return
                result;
    }

/* Получение системного интерфейса приложения */
    result = pIUnkSystem->pVTbl->QueryInterface(pIUnkSystem, &GID_IEcoSystem1, (void **) &pISys);

/* Проверка */
    if (result != 0 && pISys == 0) {
        return
                result;
    }

/* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **) &pIBus);

/* Получение идентификатора компонента для работы с памятью */
    result = pIBus->pVTbl->QueryInterface(pIBus, &IID_IEcoInterfaceBus1MemExt, (void **) &pIMemExt);
    if (result == 0 && pIMemExt != 0) {
        rcid = (UGUID *) pIMemExt->pVTbl->get_Manager(pIMemExt);
        pIMemExt->pVTbl->
                Release(pIMemExt);
    }

/* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->
            QueryComponent(pIBus, rcid,
                           0, &IID_IEcoMemoryAllocator1, (void **) &pIMem);

/* Проверка */
    if (result != 0 && pIMem == 0) {
/* Освобождение системного интерфейса в случае ошибки */
        pISys->pVTbl->
                Release(pISys);
        return
                result;
    }

/* Выделение памяти для данных экземпляра */
    pCMe = (CEcoLab1 *) pIMem->pVTbl->Alloc(pIMem, sizeof(CEcoLab1));

/* Сохранение указателя на системный интерфейс */
    pCMe->m_pISys = pISys;

/* Сохранение указателя на интерфейс для работы с памятью */
    pCMe->m_pIMem = pIMem;

/* Установка счетчика ссылок на компонент */
    pCMe->m_cRef = 1;

/* Создание таблицы функций интерфейса IEcoLab1 */
    pCMe->m_pVTblIEcoLab1 = &g_x277FC00C35624096AFCFC125B94EEC90VTbl;

    pCMe->m_pVTblIEcoConnectionPointContainter = &g_x0000000500000000C000000000000046VTblCPC;

/* Инициализация данных */
    pCMe->m_Name = 0;

/* Возврат указателя на интерфейс */
    *
            ppIEcoLab1 = (IEcoLab1 * )
    pCMe;

/* Освобождение */
    pIBus->pVTbl->
            Release(pIBus);

    return 0;
}

/*
 *
 * <сводка>
 *   Функция Delete
 * </сводка>
 *
 * <описание>
 *   Функция освобождения экземпляра
 * </описание>
 *
 */
void deleteCEcoLab1(/* in */ IEcoLab1
                             *pIEcoLab1) {
    CEcoLab1 *pCMe = (CEcoLab1 *) pIEcoLab1;
    IEcoMemoryAllocator1 *pIMem = 0;

    if (pIEcoLab1 != 0) {
        pIMem = pCMe->m_pIMem;
/* Освобождение */
        if (pCMe->m_Name != 0) {
            pIMem->pVTbl->
                    Free(pIMem, pCMe
                    ->m_Name);
        }
        if (pCMe->m_pISys != 0) {
            pCMe->m_pISys->pVTbl->
                    Release(pCMe
                                    ->m_pISys);
        }
        pIMem->pVTbl->
                Free(pIMem, pCMe
        );
        pIMem->pVTbl->
                Release(pIMem);
    }
}
